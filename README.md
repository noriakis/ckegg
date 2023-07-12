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
