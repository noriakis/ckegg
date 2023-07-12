# ckegg


## Installation

```sh
git clone https://github.com/noriakis/ckegg
cd ckegg && mkdir build
cmake -S . -B build
cmake --build build
```

## Usage

```
Usage: ckegg aa [options]
Options: -p CHAR  KEGG PATHWAY ID for global map
         -x INT   Width of AA [100]
         -y INT   Height of AA [50]
         -f CHAR  File describing KO (one line per KO, no prefix `ko:`)

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
ckegg aa -pko01100
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
echo K00055 | ckegg aa -pko01100 -f- -x100 -y50
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
echo CDKN2A | ckegg aa -phsa04110 -f- -x60 -y20

```

```
   .  ..  ..           .  .    .             .          .  .
     .     .            .     .    .         .       .   .
                                             .

     .     .             C                               .
.    .     .                  .  .   .       .    .
                  .      .                               .
     .            .                               .   .
     .                 .      .              .        .
                                     .            .      .
  U   .  .   .  .   .      .     .           .    .      .
                           .                    .
                               .               .
    .      .        .      .         .     .
    .      .        .      .         .     .     .
 .                         .                             .
 .       .   .   .     .   .     .    .   .              .
         .   .         . . .                           .
         .   .                                         .
                         .

C: CDKN2A F: FZR1 M: MCM2 O: ORC6 A: ANAPC10 a: ANAPC10 S: SKP1 s: SKP1 c: CDK1 B: BUB1B P: PCNA
p: PLK1 T: ATM D: DBF4 m: MAD2L2 b: BUB1 U: BUB3 d: CDC14B Y: YWHAQ f: SFN H: CHEK1
K: CDKN1A R: PRKDC 2: MDM2 r: CREBBP k: SKP2 y: PKMYT1 W: WEE2 t: PTTG2 E: ESPL1 1: SMC1B
B: SKP2 U: RB1 G: GADD45G m: RB1 5: TP53 N: CDKN1B n: CDKN2B g: TGFB1 4: SMAD4 b: SMAD2
7: CDC7 0: CDC20 G: CDC25B Y: CDC45 6: CDC6 K: CDC25A 3: GSK3B 0: CDK1 U: CCNB3 n: CCNA2
3: CDK7 7: CDK2 W: CDK2 7: CDK4 h: CCNH 5: CCNA2 e: CCNE1 F: CCND1 L: MAD1L1 0: TTK
D: CDKN2C E: CDKN2D U: CDKN2A b: SMC3 A: STAG1 G: RAD21 l: RBL1 Y: E2F4 F: MYC Z: ZBTB17
p: ABL1 T: TFDP1 4: E2F1 N: HDAC1 n: RB1 2: RBL1 T: TFDP1 T: E2F4 H: TFDP1 8: NDC80
u: AURKB Y: KNL1 h: MAD2L1BP I: TRIP13 g: SMC1B H: SMC3 X: ATRX i: NIPBL l: MAU2 S: CDT1
t: MTBP 8: TICRR o: ESCO1 A: RAD21 s: STAG1 x: DDX11 t: SMC1B K: SMC3 D: PDS5B w: WAPL
T: RAD21 k: STAG1 C: CDCA5 r: HDAC8 c: CDK1 0: PLK1 4: SGO1 u: PPP2CA A: CDKN1A b: FBXO5
p: TP53

```

## TODO

- [ ] edge implementation
