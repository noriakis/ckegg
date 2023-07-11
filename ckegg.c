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
int draw(int r, int c, Array x, Array y, char *text) {
    char *points[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            points[i][j] = ' ';
        }
    }
    for (int i=0; i<x.used; i++) {
        for (int j=0; j<y.used; j++) {
            points[x.array[i]][y.array[i]]=text[i];
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

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    int sxmax = 100;
    int symax = 50;
    int c;
    char *pathway;

    while ((c = getopt(argc, argv, "p:x:y:")) >= 0) {
	switch (c) {
		case 'p': pathway = optarg; break;
		case 'x': sxmax = atoi(optarg); break;
		case 'y': symax = atoi(optarg); break;
	}
    }


    char url[255];
    strcpy(url, "https://rest.kegg.jp/get/");
    strcat(url,  pathway);
    strcat(url, "/kgml");

    struct string s;
    init_string(&s);

    //fprintf(stderr, "%s\n", url);
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

    //initArray(&R, 10);
    //initArray(&G, 10);
    //initArray(&B, 10);

    //int r, g, b;
    char *tex;
    // large in ko01100, around 32000
    char text[50000];
    int numel = 0;

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
                           if (strcmp(hex, "#B3B3E6")==0) tex = 'c'; // carbo
                           else if (strcmp(hex, "#F06292")==0) tex = 's'; // secondary
                           else if (strcmp(hex, "#FFB3CC")==0) tex = 'v'; // vitamin
                           else if (strcmp(hex, "#FF8080")==0) tex = 'n'; // nucleotide
                           else if (strcmp(hex, "#6C63F6")==0) tex = 'C'; // carbo
                           else if (strcmp(hex, "#FFCC66")==0) tex = 'a'; // amino acid
                           else if (strcmp(hex, "#80CCB3")==0) tex = 'l'; // lipid
                           else if (strcmp(hex, "#DA8E82")==0) tex = 'x'; // xeno
                           else if (strcmp(hex, "#80CCCC")==0) tex = 'L'; // lipid
                           else if (strcmp(hex, "#9EE284")==0) tex = 't'; // terpe
                           else if (strcmp(hex, "#99CCFF")==0) tex = 'g'; // glycan
                           else if (strcmp(hex, "#FF9900")==0) tex = 'o'; // other aa 
                           else if (strcmp(hex, "#CC99FF")==0) tex = 'e'; // en
                           else if (strcmp(hex, "#8080F7")==0) tex = 'r'; // carbo 
                           else tex='.';
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
                                //insertArray(&R, r);
                                //insertArray(&G, g);
                                text[numel] = tex;
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
    //    printf("%i,%i\n", scaleX.array[i], scaleY.array[i]);
    //}
    //printf("%i,%i,%i\n",x.used,y.used,strlen(text));

    draw(symax,sxmax,scaleY,scaleX,text);
    free(s.ptr);
    curl_easy_cleanup(curl);
    xmlCleanupParser();
    //fprintf(stderr, "%s\n",argv[1]);
    FILE *fh = fopen(argv[1], "r");
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
