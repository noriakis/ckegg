#include <unistd.h>
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <libxml/xmlreader.h>
#include <libxml/xpath.h>

struct string {
  char *ptr;
  size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = realloc(s->ptr, new_len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}


// Array definition
// https://stackoverflow.com/questions/3536153/c-dynamically-growing-array

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}


// Drawing
int draw(int r, int c, Array x, Array y, char *text, Array match, int doko) {
    char points[r+1][c+1];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            points[i][j] = ' ';
        }
    }
    for (int i=0; i<x.used; i++) {
        for (int j=0; j<y.used; j++) {
            if (doko!=0) {
                if (match.array[i]==1) {
                    if (text[i]=='.') {
                        points[x.array[i]][y.array[i]]='*';
                    } else {
                        points[x.array[i]][y.array[i]]=text[i];
                    }
                } else {
                    points[x.array[i]][y.array[i]] = '.';
                }
            } else {
                points[x.array[i]][y.array[i]]=text[i];
            }
        }
    }
    for (int i=0; i<r; ++i)
    {
        for (int j=0; j<c; ++j) {
                printf("%c", points[i][j]);
        }
        printf("\n");
    }
}


int ckegg_aa(int argc, char *argv[]) {


    if (argc == 1 && isatty(fileno(stdin))) {
	fprintf(stderr, "Usage: ckegg aa [options]\n");
	fprintf(stderr, "Options: -p CHAR  KEGG PATHWAY ID for global map\n");
	fprintf(stderr, "         -x INT   Width of AA [100]\n");
	fprintf(stderr, "         -y INT   Height of AA [50]\n");
	fprintf(stderr, "         -f CHAR  File describing KO (one line per KO, no prefix `ko:`)\n");
        fprintf(stderr, "\n");
        fprintf(stderr, "Description of characters in AA:\n");

        fprintf(stderr, "c: #B3B3E6 Carbohydrate metabolism [Amino sugar and nucleotide sugar metabolism]\n");
	fprintf(stderr, "s: #F06292 Biosynthesis of other secondary metabolites [Biosynthesis of various secondary metabolites - part 2]\n");
	fprintf(stderr, "v: #FFB3CC Metabolism of cofactors and vitamins [Biosynthesis of cofactors]\n");
	fprintf(stderr, "n: #FF8080 Nucleotide metabolism [Purine metabolism]\n");
	fprintf(stderr, "C: #6C63F6 Carbohydrate metabolism [Glycolysis / Gluconeogenesis]\n");
	fprintf(stderr, "a: #FFCC66 Amino acid metabolism [Biosynthesis of amino acids]\n");
	fprintf(stderr, "l: #80CCB3 Lipid metabolism [Glycerolipid metabolism]\n");
	fprintf(stderr, "x: #DA8E82 Xenobiotics biodegradation and metabolism [Degradation of aromatic compounds]\n");
	fprintf(stderr, "L: #80CCCC Lipid metabolism [Fatty acid metabolism]\n");
	fprintf(stderr, "t: #9EE284 Metabolism of terpenoids and polyketides [Biosynthesis of 12-, 14- and 16-membered macrolides]\n");
	fprintf(stderr, "g: #99CCFF Glycan biosynthesis and metabolism [Various types of N-glycan biosynthesis]\n");
	fprintf(stderr, "o: #FF9900 Metabolism of other amino acids [Glutathione metabolism]\n");
	fprintf(stderr, "e: #CC99FF Energy metabolism [Oxidative phosphorylation]\n");
	fprintf(stderr, "r: #8080F7 Carbohydrate metabolism [Citrate cycle (TCA cycle)]\n");

	return 1;
    }

    FILE *fp;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    int sxmax = 100;
    int symax = 50;
    int c;
    char pathway[50];
    char fileName[128];
    int doko = 0;

    while ((c = getopt(argc, argv, "p:x:y:f:d:")) >= 0) {
	switch (c) {
		case 'p': strcpy(pathway,optarg); break;
		case 'x': sxmax = atoi(optarg); break;
		case 'y': symax = atoi(optarg); break;
                case 'f': doko = 1;strcpy(fileName, optarg); break;
	}
    }

    // Read KO file
    char *buffer = NULL;
    size_t size = 0;

    if (doko != 0) {
        fp = strcmp(fileName, "-") == 0 ? stdin : fopen(fileName, "r");
        if (fp == NULL) {
                printf("Can't read the file specified by -f");
                exit (1);
        }

        fseek(fp, 0, SEEK_END); 
        size = ftell(fp);
        rewind(fp);
        buffer = malloc((size + 1) * sizeof(*buffer));

        if (strcmp(fileName, "-")==0) {
            fread(buffer, 500, 1, fp);
        } else {
            fread(buffer, size, 1, fp);
        }

        buffer[size] = '\0';
        if (fp != stdin)
            fclose(fp);
    }



    // Obtain KGML from REST API
    char url[255];
    strcpy(url, "https://rest.kegg.jp/get/");
    strcat(url,  pathway);
    strcat(url, "/kgml");

    struct string s;
    init_string(&s);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

    res = curl_easy_perform(curl);
    xmlTextReaderPtr reader = xmlReaderForDoc(s.ptr,NULL,"UTF-8",1);

    // node reading
    int ret;
    Array x;
    Array y;
    Array match;
    //Array R;
    //Array G;
    //Array B;
    xmlChar *name, *value;
    int xmax = 0;
    int ymax = 0;
    int xmin = 10000;
    int ymin = 10000;
    initArray(&x, 10);
    initArray(&y, 10);
    initArray(&match, 10);

    //initArray(&R, 10);
    //initArray(&G, 10);
    //initArray(&B, 10);

    //int r, g, b;
    char tex[5];
    // large in ko01100, around 32000
    char text[50000];
    int numel = 0;
    int koflag = 0;

    if (reader != NULL) {
        ret = xmlTextReaderRead(reader);
        while (ret == 1)
        {
            name = xmlTextReaderName(reader);
            if (name == NULL)
                name = BAD_CAST "--";
            value = xmlTextReaderValue(reader);
            while (xmlTextReaderMoveToNextAttribute(reader))
            {

                if (xmlTextReaderName(reader) != NULL)
                {

                    if (xmlStrcmp(xmlTextReaderName(reader), BAD_CAST "fgcolor") == 0)
                    {
                           char *hex = (char*)xmlTextReaderValue(reader);
                           if (strcmp(hex, "#B3B3E6")==0) *tex='c'; // carbo
                           else if (strcmp(hex, "#F06292")==0) *tex='s'; // secondary
                           else if (strcmp(hex, "#FFB3CC")==0) *tex='v'; // vitamin
                           else if (strcmp(hex, "#FF8080")==0) *tex='n'; // nucleotide
                           else if (strcmp(hex, "#6C63F6")==0) *tex = 'C'; // carbo
                           else if (strcmp(hex, "#FFCC66")==0) *tex = 'a'; // amino acid
                           else if (strcmp(hex, "#80CCB3")==0) *tex = 'l'; // lipid
                           else if (strcmp(hex, "#DA8E82")==0) *tex = 'x'; // xeno
                           else if (strcmp(hex, "#80CCCC")==0) *tex = 'L'; // lipid
                           else if (strcmp(hex, "#9EE284")==0) *tex = 't'; // terpe
                           else if (strcmp(hex, "#99CCFF")==0) *tex = 'g'; // glycan
                           else if (strcmp(hex, "#FF9900")==0) *tex = 'o'; // other aa 
                           else if (strcmp(hex, "#CC99FF")==0) *tex = 'e'; // en
                           else if (strcmp(hex, "#8080F7")==0) *tex = 'r'; // carbo 
                           else *tex='.';
                    }
                    if (xmlStrcmp(xmlTextReaderName(reader), BAD_CAST "name") == 0) {
                        char *koname = (char*)xmlTextReaderValue(reader);
                        // avoid graphics_name
                        if (koname[2]==':') {
                            if (koname[0]=='k') {
                                koflag = 0;
                                char *koptr = strtok(koname, " ");
                                char *qptr = strtok(buffer, "\n");
                                while (koptr != NULL)
                                {

                                   char dst[5];
                                   memcpy(dst, &koptr[3], 6);
                                   dst[6] = '\0';

                                   while (qptr != NULL)
                                   {
                                        //fprintf(stderr, "%s,%s\n", dst, qptr);
                                        if (strcmp(dst, qptr) == 0) {koflag = 1;}
                                        qptr = strtok(NULL, "\n");
                                   }
                                   koptr = strtok(NULL, " ");
                                }
                            }
                        }
                    }
                    if (xmlStrcmp(xmlTextReaderName(reader), BAD_CAST "coords") == 0)
                    {
                        char *ptr = strtok(xmlTextReaderValue(reader), ",");
                        int flag = 0;
                        while(ptr != NULL)
                        {
                            int cur;
                            cur = atoi(ptr);
                            //printf("%i",cur);
                            if (flag % 2 == 0) {
                                if (cur > xmax) {xmax = cur;}
                                if (cur < xmin) {xmin = cur;}
                                insertArray(&x, cur);
                                insertArray(&match, koflag);
                                //insertArray(&R, r);
                                //insertArray(&G, g);
                                text[numel] = *tex;
                                numel = numel + 1;
                                //insertArray(&B, b);

                            } else {
                                if (cur > ymax) {ymax = cur;}
                                if (cur < ymin) {ymin = cur;}
                                insertArray(&y, cur);
                            }
                            flag = flag+1;
                            ptr = strtok(NULL, ",");
                        }
                    }
                }
            }
        xmlFree(name);
        xmlFree(value);
        ret = xmlTextReaderRead(reader);
        }
    }

    int xsize;
    int ysize;

    xsize = x.used;
    ysize = y.used;
    
    // Scale to fit in the window
    Array scaleX;
    Array scaleY;
    initArray(&scaleX, 10);
    initArray(&scaleY, 10);

    for (int i=0; i<xsize; i++) {
        insertArray(&scaleX, sxmax * (((double)x.array[i] - (double)xmin) / ((double)xmax - (double)xmin )));
    }
    for (int i=0; i<ysize; i++) {
        insertArray(&scaleY, symax * (((double)y.array[i] - (double)ymin) / ((double)ymax - (double)ymin )));
    }

    // sanity check
    //printf("%i,%i,%i,%i\n", xmax,xmin,ymax,ymin);
    //for (int i=0; i<xsize; i++) {
    //    if (match.array[i]==1) {
    //        printf("%i", match.array[i]);
    //    }
    // }
    //printf("%i,%i,%i,%i,%i,%i\n",x.used,y.used,strlen(text),match.used,scaleX.used,scaleY.used);
    //for (int i=0; i<scaleX.used; i++) {
    //    printf("%i,%i\n",scaleX.array[i],scaleY.array[i]);
    //}
    draw(symax,sxmax,scaleY,scaleX,text,match,doko);
    free(s.ptr);
    curl_easy_cleanup(curl);
    xmlCleanupParser();
    //fprintf(stderr, "%s\n",argv[1]);
    // FILE *fh = fopen(argv[1], "r");
    return 0;
}



static int usage()
{
        fprintf(stderr, "\n");
        fprintf(stderr, "Usage:   ckegg <command> <arguments>\n");
        fprintf(stderr, "Version: 0.0.1\n\n");
        fprintf(stderr, "Command: aa       download and parse XML for drawing ascii art\n");
        return 1;
}

int main(int argc, char *argv[])
{
        if (argc == 1) return usage();
        if (strcmp(argv[1], "aa") == 0) return ckegg_aa(argc-1, argv+1);
        else {
                fprintf(stderr, "[main] unrecognized command '%s'. Abort!\n", argv[1]);
                return 1;
        }
}
