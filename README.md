# ckegg


## Installation

```sh
git clone https://github.com/noriakis/ckegg
cd ckegg && mkdir build
cmake -S . -B build
cmake --build build
```

## Usage

If you specify file name ending with `.xml` to `-p`, read from the local.

```
Usage: ckegg aa [options]
Options: -p CHAR  KEGG PATHWAY ID
         -x INT   Width of AA [100]
         -y INT   Height of AA [50]
         -s       Show node names
         -n       No node mode, useful for ko01100
         -f CHAR  File describing ID (one line per ID, no prefix in KO like [ko:])

Description of characters in AA:
c: #B3B3E6 Carbohydrate metabolism [Amino sugar and nucleotide sugar metabolism]
s: #F06292 Biosynthesis of other secondary metabolites [Biosynthesis of various secondary metabolites - part 2]
v: #FFB3CC Metabolism of cofactors and vitamins [Biosynthesis of cofactors]
n: #FF8080 Nucleotide metabolism [Purine metabolism]
C: #6C63F6 Carbohydrate metabolism [Glycolysis / Gluconeogenesis]
a: #FFCC66 Amino acid metabolism [Biosynthesis of amino acids]
l: #80CCB3 Lipid metabolism [Glycerolipid metabolism]
x: #DA8E82 Xenobiotics biodegradation and metabolism [Degradation of aromatic compounds]
L: #80CCCC Lipid metabolism [Fatty acid metabolism]
t: #9EE284 Metabolism of terpenoids and polyketides [Biosynthesis of 12-, 14- and 16-membered macrolides]
g: #99CCFF Glycan biosynthesis and metabolism [Various types of N-glycan biosynthesis]
o: #FF9900 Metabolism of other amino acids [Glutathione metabolism]
e: #CC99FF Energy metabolism [Oxidative phosphorylation]
r: #8080F7 Carbohydrate metabolism [Citrate cycle (TCA cycle)]
```

## Output

```
ckegg aa -pko01100 -n
```

```
             g     g ggg ggg g       gg gg g ggg g
             g  g gggggg        gg gggg  g g gg ggggg gg gg   gg           n     n          v
            gggggggg g g g g g g    ggg gg ggg    gc     gggg  g ggg   n   n    n nn   vvv vvv
              g ggg g  g g g g g    gg g g ggg g   gg gg gggggggggggsggggnnnnn nnn nnnnnnv  v
            gg gggg g gggggg     ggggg ggggggggg g gggggggggg  gggg  s   nnnnnnnnnnnnn nvvvv
            gg ggg  g  g g gg ggggg gg ggcggc gggggggggggngg nggn gnnn nnn n nn nnsnsn nvvvv
                g    l       l g  ggggcgggggg gg g cggggg g g  gg gnn n  nnnnnnnnnsnsnsnvv vvvvvvv v
                g l  ttt t   gggg ggggcggccccc cc cc cgggcggcnngn  snnn nn   nnnnssssss v vvvvvvvv v
        s ss ss sssstss sgg ggg gg gggccgccccccccccgcgg gcgg   gnnnnnnnnnssnsssvvvs s    vsvvv vvv
        s ss ss    tt ttsgggg gggggggccccccccc cccccccc ccccgccc n nnnn nsss sssv vv   s  sv vv  v
                t ttt t sgsss gglgclcccccc cccccccccccccCCcc c cnnn nnn nnn v   vnvv v   vvvvvv  vvs
  tt ttt ttt tttt ttttttstggg glllclscccccccccccccccccc c ccccccnnnnnnnns sn n  vvvvvvvs  svvvv v vs
      tt t ss  sst tttttst  sssclcclcgcccc cc cccccccccCCnccccc nnnnnnn        v  vvvvsssssv vvvvvvs
tttt ttt ttt t   ttttttttggggggll c g cccccccc cccccccCCcCccccnnnn ntntsaassassss ssv sssssssvvsv vs
   ttttt ttt t   lllllllllllllllll l cccccccccCcCCcCcCCCCCg   o nnnnnnssaoooaa a vvvvvsv ss    s s s
   ttttt ttt tt  l    lll   l   ll llclc lcccccCCCCCcCcCcCcccc nnnaaaaasnnsoaasas   vvss sssssssssss
sttttt ttttt tt lltllllllllllllllllllclccccccclccCC  CccCCcccc aaeasssaaanaav aaaaassvsvsvsssss ssss
st            s lltlll  lllllllll llllccccccccccC C  rcCCCca aaaaaaaaaa aaan  aaa asvsssssssssssssss
 t          s s   tllllllll  ll l llccccccccccCcCCrgrrCCCcaeae aeaaaaaaaaaanvaavavv vv vv s ssssssss
 tttttttttttstttt tltlllll ll llll lc cccccccccccCcCccgscsaaaeeaaaaaaaaaaavvsvvsvvvvvv v ssss sssss
 t  vvtvvvv vv tt tttl ttttttlll lllcccccc cccccCcnCco ooaae neeoaaovxoaaavas vvsvvvvvsvvcvvvsvvs s
  ttttttv ttttttt ttLLtttLlllllll cclctcccLccccccCacccnnooseaeeeeaavoao  anaa vvv vvvvvv s vv sss s
  tt tttttttttttt ttLL LLLlllll  tccc cccclcccccCCtclcca clteeeeaeaaaaa acaaa v vvvvvavcssvsvs ssss
 ttt tttttt tt  t ttLLLLLLLLLLLLLLLLLLLLLLlccLLcC  e CxxCCxxeaaa aaaaaooaa aaaaav vvvaa asv v   vvs
 ttt  ttt ttttttttt LLLLLLLLLLLLLc         ccccccoooooxooc aaacaaaaaaaanaa aaaaavvavvavaavv vv    s
 ttt tttt t ttttttttLLL          L LLLL LL  ccccC eelCaaaccaeaaaaaaa aanaa na  vvvvvvssvavvv v v vs
 tt   tt  t t  tttt tL LLL LLLL cc LLLL LLt ccccaaCCCCaaoxxaoasaanaaaaanaana  vavvvvvasa s vv sss
 tt  sttt t      t  LLLLLL LLLL Lc        t c ccxccxo coaaaaeaaaaaaa saaavvvv vvvsvvvvss svvv v
     stttt       tt LLL       LLcLLLLLLLLllccLcLCcCcaaaaa Lccaceaa aaaaaaaaaaaaaaavsvavsvs v  v s
   ssss t tttsst tt t tLLLLLLLLLLa cvL  LLta  ceceeac cLacLtaaeaaaaasaanaanvav avaavavavvvvv vvv vs
  ssssssstttttstttttt tttLttLLt LctvtLxx cta  c CCnnc caaastacaaaaaaaaaeeenaaa   aaoaaaaa  v      s
    t tttttttttt tt LLLL LLLLvvvcc  xxxx ex xCCCCCCCcaaaa aaaa aaeaeeaaeeenaaa asaaaasaaa ss v    s
   tttsttttsttttt L   LtL LtLttxxc x x eccac CcaeccCCaaaaa oaaaaaaaaeaaeneaeaaaaaosoasaaa ss v    s
   t ssstttttvvtL LL LLLL L L  xxxxx x eceaaCcccccacCococsoaaaxaaaavananeeaaaaaaaaao o ss sss s s s
     s st t tvvvL LL LLLL L    xxxxx xae c cCcccccaaCCca coaeoaaaaccaa eeeaaaa aa ssvavss sss sss s
     s st t tvvvL LL  LLL LLLLLxxx x x e    CCaaccc CC a a aaaaaaaoaaaa aaaaaaaaosvsvvvv sss    s s
     s st t tvvvL LL LLLxLLxxLLxxx xxxec c  cCCaccaCCCa  ao  aaa a caa aaoaaaaa  saav v v ss    s s
     s  t t  vvvLLLL aa   x xxxLxx x xex   xeeeCCCCae xacaoaa  aooaoao aoasaa  aasv vvv v   vv  s
     st t    v vLLLL LLxLLx xxx xxxxxxxex  eceeee axeccaasoaaaaaaa eaoaaaaaasvaoasvvaLs v ss    s
      t t t  xxLLaLLxLLxx xxxxxx xxx x   eeeec eccc xexaxxxaax oooooovvave vsaaaasvva   a       s
      t t t  tLLLLLLLLLxx xxx     x  xxe  ca aevca axaaa sooo xo o a   vvsvv   oosoao  v
      t t tt t LLLLL  LL   xxxx     xxaeeexaaee aa a axasssaoaoaa aa svvvo vvav oso oa
      tttttt txxLLLLxxLxx xxxxx xxxx aeeeeeeeeexeeeex x ss aoaaoaoo osoooosss vsvsssvvsvv
       tttt    xxxxx x x  xxxxx x xx xeeee  eecxee exaxasxxaxxaaaoavvvv vvsv vvsvssvvss
       t      x xx x  xxx x x       eeeee  e ecxecce  xo  xao    aavvovvvvssx vs s     v
                x    xx  x xxxx xxx e  ee e ee  eeeexs ss x xx   o  o o   ss s ss ss ss
         x xxx xxxx  x xxx x   xx xx  eeeeeeeeexe  ex a s  vvo o o    ov xxsx v  v
                x xx x xxx xa  eeeeee eeeeeeeexxe ee  aeeeeeeeea            x
                xax x x xax     eeeee x xeeeexcxxx a  xee eeeeea
                x     xx xx x  xeeeee x xeeeeeexxcxxxx eeeeeee
```

```
echo K00055 | ckegg aa -pko01100 -f- -x100 -y50 -n
```

```
             .     . ... ... .       .. .. . ... .
             .  . ......        .. ....  . . .. ..... .. ..   ..           .     .          .
            ........ . . . . . .    ... .. ...    ..     ....  . ...   .   .    . ..   ... ...
              . ... .  . . . . .    .. . . ... .   .. .. ..................... ... .......  .
            .. .... . ......     ..... ......... . ..........  ....  .   ............. .....
            .. ...  .  . . .. ..... .. ...... .............. .... .... ... . .. ...... .....
                .    .       . .  ........... .. . ...... . .  .. ... .  ................. ....... .
                . .  ... .   .... ............ .. .. ............  .... ..   .......... . ........ .
        . .. .. ....... ... ... .. .................... ....   .................... .    ..... ...
        . .. ..    .. ....... ................ ........ ........ . .... .... .... ..   .  .. ..  .
                . ... . ..... ............ ................. . .... ... ... .   .... .   ......  ...
  .. ... ... .... ........... ......................... . ............... .. .  ........  ..... . ..
      .. . ..  ... .......  .............. .. ................. .......        .  .......... .......
.... ... ... .   ................ . . ........ ................... .............. ... ........... ..
   ..... ... .   ................. . ......................   . .............. . ....... ..    . . .
   ..... ... ..  .    ...   .   .. ..... ..................... ...a..............   .... ...........
...... ..... .. ...................................  ......... .............. ................. ....
 .            . ......  ......... ............... .  ....... .......... ....  ... ..................
 .          . .   .........  .. . ............................ .................... .. .. . ........
 ................ ........ .. .... .. ................................................ . .... .....
 .  ....... .. .. .... ......... ......... ........... ..... ................ ................... .
  ....... ....... ............... .....................................  .... ... ...... . .. ... .
  .. ............ .... ........  .... .................. .............. ..... . .............. ....
 ... ...... ..  . ...............................  . ........... ......... ...... ..... ... .   ...
 ...  ... ......... ..............         ............... ............... ................ ..    .
 ... .... . ...........          . .... ..  ..... .................. ..... ..  ............. . . ..
 ..   ..  . .  .... .. ... .... .. .... ... ................................  .......... . .. ...
 ..  .... .      .  ...... .... ..        . . ....... .............. ........ .......... .... .
     .....       .. ...       ........................... ........ ....................... .  . .
   .... . ...... .. . ............ ...  ....  ....... ........................ ............. ... ..
  ................... ......... ........ ...  . ..... ........................   ........  .      .
    . .......... .. .... .........  .... .. ............. .... ............... .......... .. .    .
   .............. .   ... ........ . . ..... ............. .............................. .. .    .
   . ............ .. .... . .  ..... . ............................................. . .. ... . . .
     . .. . ..... .. .... .    ..x.. ... . ............. ............. ....... .. ....... ... ... .
     . .. . ..... ..  ... ........ . . .    ....... .. . . ............ ................ ...    . .
     . .. . ..... .. ............x ..... .  ...........  ..  ... . ... ........  .... . . ..    . .
     .  . .  ....... ..   . ...... . ...   .......... .......  ....... ......  .... ... .   ..  .
     .. .    . ..... ...... ... .........  ...... ................ .................... . ..    .
      . . .  ............ .x.... ... .   ..... .... .......... ........... ..........   .       .
      . . .  ............ ...     .  ...  .. ..... ..... .... .. . .   .....   ......  .
      . . .. . .....  ..   ....     ........... .. . ............ .. ..... .... ... ..
      ...... ............ ..... .... ................ . .. ........ ......... ...........
       ....    ..... . .  ..... . .. .....  ...... .................... .... ..........
       .      . .. .  ... . .       .....  . .......  ..  ...    ............ .. .     .
                .    ..  . .... ... .  .. . ..  ...... .. . ..   .  . .   .. . .. .. ..
         . ... ....  . ... .   .. x.  ...........  .. . .  ... . .    .. .... .  .
                . .. . ... ..  ...... ........... ..  ..........            .
                ... x . ...     ..... . .......... .  ... ......
                .     .. .. .  ...... . .............. .......
```

For the pathways other than global map, nodes are represented as characters based on graphics name.
If chracters are already used, random character will be assigned.


```
ckegg aa -phsa03440 -x50 -y20
```
```
                                             ~
                                             .
% s       x                       m    r...i..  t
          3                       G    N   &.(..I.
                                           ... <
U U       z        b               0    P  . l
7                  D A  5 a             &  S.c....
                          x

2         b                        =    8



K _       x  6
q         9                        p

                     L e
          4  0
          k  K


```

Show the meaning of the characters.


```
ckegg aa -phsa05230 -y40 -s

```

```
                                                                      }
                                            b                    T
                                             .
                                              U            T          o                .Y
                                                                                       .
_   L   B g  9   )    +    q    ^    _  p   q          4               <               .
                                                    n                                  I
                                                                       4               .
                                                   L        z                           H
    3                                       W                     J     i       G

                                                                      6

                                                                      ~



                                                                        l
    E... .....R... . ....... r... . ....... A... . ....... a .... . .    .   . ... . . .M... ......U
                                                                                       . ... .     ~
                                                                                       .  .. ..
                             0                         Y   )  =     F    V    2        .   .. .    {
                           F   &                                  p                    .    . . .  Y
                                                                                       ...    .   .
                                                                                       . .    . ..
                                             '                  x     2                .  .    .
         .!                                  .                                         .        .
    .. ..G                                    E            5          z                i.. .     ...
     ..                                                                                ....      ...
      .   <                             K                              U               ..... . .....
C   S  3     c    7     %    5    o   7     0      .P  T                               ......  .....
         G           f          #                  .                  m                 ..... ......
                                              D    d       b                           .  ..... . .
                | !                                              &                     .... . ......
    s           .                           1                           (              ..  .. .....
                 D......N                          &                      q  N   7     ..     .....
    e.....  .......                                                        n           .      .....
    %.............. k.... .  ........ t...... .......  O ..... .  .    .     . ..... .  h
    T                .       .
A                                     .

S: SLC2A1 C: C00031 c: C00092 0: C00022 3: C00031 G: GCK 6: C00064 2: C00025 1: C00186 s: SLC16A3 L: SLC2A1
_: C00031 9: C00092 q: C00022 B: C00031 g: GCK 4: C00024 z: C00036 5: C00158 x: C00311 z: C00026
U: C00042 m: C00122 &: C00149 b: C00036 l: GLS2 M: MYC Y: MYC I: SIRT6 H: HIF1A h: HIF1A
P: PDHA1 7: C00704 G: C00704 i: SIRT3 p: PKM K: PKM D: LDHAL6A d: PDK1 E: EGFR R: HRAS
r: RAF1 A: MAP2K1 a: MAPK1 e: EGFR %: ERBB2 T: MET k: PIK3CA t: AKT3 O: MTOR Y: SLC2A1
{: SLC2A2 x: HK1 =: PGAM4 8: PKM K: LDHAL6A 0: PDK1 U: GLS2 (: SIRT3 i: SIRT6 <: HK1
&: C00022 ~: SLC1A5 }: SLC1A5 ~: SLC1A5 n: PDHA1 L: PDK1 3: SLC16A3 7: C00085 ): C00158 ): C00085
W: C00186 7: C00074 5: C00197 _: C00074 q: C00197 F: C00065 0: C00037 &: C00097 !: C00665 |: TIGAR
D: TP53 o: C00631 %: C00354 ^: C00631 +: C00354 f: PFKL N: PTEN #: PGAM4 E: SCO2 ': TP53
U: SCO2 b: TP53 }: SLC7A5 A: C00123 !: G6PD G: TP53 Y: C00024 =: C00311 F: C00026 p: IDH1
T: C00311 o: C00036 <: C00042 4: C00122 J: C00149 q: C00041 N: C00152 n: C00049 V: C00148 2: C00062
T: C00158 ): PFKL T: C00024
```


```
echo CDKN2A | ckegg aa -phsa04110 -f- -x60 -y20 -s

```

```
           .     .                          .       .
     .  .  .      .                   .  .  .                               .                .  .  .
        .                                .        .       .                 .           .       .
                                                                            .


                  .                                                                             .
        .         .                        C                                                    .
.       .         .                        .      ... .........             .      .            .
.                              .       .. ... .........       .                    .            .
 .                             .        ..   ..   .  .. . .   .                    .            .
 .      .                                .     .  .  .     .  .                    .      .
  .     .                          .....  ............. .......                    .      .
        ..                             .  .    ..  ..   .     .             .      .
.  .    .                                   .   .   ...  .........    .......      .            .
.   U     .    .     .      .     .           .....   .... .  .........     ........            .
.   .                                         .    .. .  ....         . .     ....
.  .                                          .           ..  .. .        .    .
.    .   ..... . .   ..... .       ..... .......... ... .....   .  .    .. ..... .
.                    .       ..    .    .  .           ..         ..      ..   ..
      .            .              . .    .   ..           .  .          .   .   .
      .            .              .          .               .............  .......
                                                             .. ....  ..  . .
  .                                          .               .     . ..       .                 .
  .            .     ........                .         .       .      .                         .
                            .         .
               .     .                .   .  .                                               .
               .     .                                                                       .
                                           .                                                 .
                                           .                                                 .

C: CDKN2A F: FZR1 M: MCM2 O: ORC6 A: ANAPC10 a: ANAPC10 S: SKP1 s: SKP1 c: CDK1 B: BUB1B P: PCNA
p: PLK1 T: ATM D: DBF4 m: MAD2L2 b: BUB1 U: BUB3 d: CDC14B Y: YWHAQ f: SFN H: CHEK1
K: CDKN1A R: PRKDC 2: MDM2 r: CREBBP k: SKP2 y: PKMYT1 W: WEE2 t: PTTG2 E: ESPL1 1: SMC1B
_: SKP2 q: RB1 G: GADD45G B: RB1 5: TP53 N: CDKN1B n: CDKN2B g: TGFB1 4: SMAD4 z: SMAD2
7: CDC7 0: CDC20 x: CDC25B z: CDC45 6: CDC6 U: CDC25A 3: GSK3B m: CDK1 &: CCNB3 b: CCNA2
G: CDK7 %: CDK2 Y: CDK2 {: CDK4 h: CCNH x: CCNA2 e: CCNE1 =: CCND1 L: MAD1L1 8: TTK
K: CDKN2C 0: CDKN2D U: CDKN2A (: SMC3 i: STAG1 <: RAD21 l: RBL1 &: E2F4 ~: MYC Z: ZBTB17
}: ABL1 ~: TFDP1 n: E2F1 L: HDAC1 3: RB1 7: RBL1 ): TFDP1 ): E2F4 W: TFDP1 7: NDC80
u: AURKB 5: KNL1 _: MAD2L1BP I: TRIP13 q: SMC1B F: SMC3 X: ATRX 0: NIPBL &: MAU2 !: CDT1
|: MTBP D: TICRR o: ESCO1 o: RAD21 %: STAG1 ^: DDX11 +: SMC1B #: SMC3 E: PDS5B w: WAPL
': RAD21 U: STAG1 b: CDCA5 }: HDAC8 A: CDK1 !: PLK1 G: SGO1 Y: PPP2CA =: CDKN1A F: FBXO5
p: TP53

```

## TODO

- [ ] edge type implementation
