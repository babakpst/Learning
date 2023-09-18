
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Codec
{
 public:
  const string div = "\n";
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs)
  {
    string out = "";
    // for (auto c:strs) out +=c+div;
    for (auto c : strs) out += div + to_string(c.size()) + div + c;
    return out;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s)
  {
    cout << s << endl;
    vector<string> out;
    int st = 0, end = 0;
    while (end < s.size())
    {
      if (s.substr(end, div.size()) == div)
      {
        out.push_back(s.substr(st, end - st));
        st = end + div.size();
        end = st;
      }
      else
        end++;
    }
    return out;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  vector<string> strs{"Hello", "World"};
  // vector<string>
  // strs{"7YJ}-fN(znA9^cKSX\\\\|J3zl[qW}$B&GJFR","&eIecW~U0M@4EO])MrqU7b;nOm7vEdu*!h4@zSsKvl_Z&wm9p}mgNF]dPS)F!IjJ~,v$Lx.`sEs(F8o_U);$`=bp(J)pU|1tm.~KE]04PGR`0(BBT`n&J~1JQQ?cU4NKj1yM
  // yO6N0SUDopz6DXYFZ<Md6_ZA-",".S2^>b8e!*cv()$QDzgG~Opv=Bymb;e|<$:)1F!4,^@?Oykw!8=|nIegX&<4c2wm?^i,&ZuYNHc4&)-(5P4$={aglb
  // j)]/]^vALm/=2AK,|$|ohH pSE@-TUW8YQj9?ZZ!.TB/P_i(wFF!@6,Nz;(0TjxYV~($","c?jT
  // 0YpUi?{mgPSC=AA.NEE5F#/mI;n!XOs;>7?]27r7Ps//LSSuL5T)8@:W*?pd>XgmBr%ASAV$T%H{,etmdAzQ3n,O$hwqj,*Zd8mHBdx@b)Ku","0<79@*oHGjZ1msv5@<xe<HQuD}*WwFmN_1]z-o%GV435iNm&;;``O5s7/F<|_wxQm;nfmhX@`,DjNv}a,H}=%.#:}##:}z^dvAX{jqa[RP8]Y.(I$W=[N&EF_f]~25","4Z^99$WH$p{}dc%jc!i+j}1(z29)S2*$u&eU!PpS^RQ0@yzQ^z?fG!NY]veF1t^Wp8{(ct7qj}
  // Hy{*a=qk[!","AtR`/B-fn.mW =+HfSr-^I5o+hsO|Af,g&ir4K
  // xID>/x[&#1R+ww,xfNj><q_Wt9-C;)7mBOFZP#)OnyMO-ouOeu}6M#sHPw~d[s7p-5NZ,W~uO,YGi<nxiZD8L@)Lq>P","pHE?DxH9yL|M/^n#>rS!1hP!rq)((=$O:Jwe92%MWWkUFTuzKw4pbuli8)D~*kJI9]3DNjZ:=N2t?Y(
  // m]Ofl!&qjN-fZ2)6<[bA<I bhG.~o|2x8`kN|md lnmo&B]!^,.j@F","3=sk !uurPo+v{#jR
  // wOJ@k#a#V2<>m_D9-k6Z",".1NV_|W5#90Ki(5IJz**Sy0vF2AeyRRsl[<QAI`kocN#fWVc!
  // z3q^B8x.c)*.XnZ|@%#.o3Ht}$-THVCmLl_k;VOa~7~fU87=R%q$ISf*<B`H<iA+J?N/fH0r`qq_>]!#?T<_(#^rr{=5.u@7","2(Ol%(uupQN`eK&>8Q~h;}OTn-(YBX`bTvcI<$:7[BpE,z
  // yFJ3Ec;N%Cagc6ezBLa#.nSgglh9V$, |5i$vi9XC*_%<}l5$}SgX)SoMiD%4kuxy|9HT<J7
  // 4Y_X",":+i}V$KjFw3j4p7Y)f!0_Lg?GZDbwo_6Eq^:3T[pr-OJ55yb2=z&C+N<<?I|k)/s$=)5.ULEs=L(gfC-z0:Sn:3WaK?n*~VecJo[0Xn
  // lf(]Q%HP9H<WF.m0d]qJ2?p.<BjQ.?5hV>9<1mJu&U+Nv)8E?%`S,SU2kOau`X[kfD-Q.{&~20~84nf_/7Af!L}U?g,S|","omF?S`lqqq/jAw+aO8VG=9+_!~@k7I[OQpdJG^4svN+FMsXpSox+c09`KumhnIumnn","NWwQ#k)&`bCTyKZ(EeU5-qAsB7i>21p$L[IitG`,_g&
  // 7wYeTCgJ F~:K?/cw<X+?1#!7NxXF#=;&OO6GDlLen&zoctQ0%kxSD ","ul(B9[>WBC5uFdoO+m
  // mETz,Q#2G?sRTbF}K`o^|zU}8?_+ZoxP6XTE","Y3$Y3zu!1=-7
  // r.@pppnq0b^QUHxVsE4Dg4fX4J[BpTl.!#f4#19X),aYKzrfS/ZjK[,N}
  // (p%OWr98mB7hv,;swc>hD!{h:{q!h&W","u#|S5ub3F{^+8]GO@Mp<ZIJ[<8QpNopR9h[Q<fj]k>dGRqzid%`<-/v];Iv6p--rq/{%4zCyxSp9H6
  // P?VATxc-@;Hu,flzaye197>YP?a|C?5k8R&","+D~Sf9TDZ-3)3]XML8A3@-MW9/dH4S~0~:9LK*9ecC8B*KTR2]5P}Q>E?iIk/YGZ1zHz]]$G7R$Q+;{TNmh@/$`>BHW1CRnQBh#d_<OXq[LtD^}7avl.yR=b..[naI{q;vK8CrZ1IT&v[g%%vg7~|/+$}
  // F?=Mq.>?BDBCteX4@P:7@v~LNrxm$T)CxWc3&B&I>k.","HsV|~uOdxF^lo{G]}EZ_V&/bu-7FH-TN8!kUP&{uvy}:NJA@x]Ghbc2E@q4(5a|[aP6LMMLuS08@Zt+I$ZV.p`82p??jzF&Z:a$x@d-#K(;;4i2
  // :bA1M2{60n+sMJDE&gM{}]g.Jy6.piY2#?K7Ur2wAX6T^!xfb","?bcmb~Aw(Rxt|Vk$_afSn8#HP.G0!:;wQgq=1
  // SDQ}TCJ1`5%`2HO$8]OP31cG,bI+Z6ELxg<$;F#d`<trTLm!kUR(BJcLI8`iSrt&3;jBZb]1*hlne||e|Kv Lr)
  // A{u]=MBH27Yl*^?tWXEMyRA1N}}uGVZ%?S)Jy(_B]o=vpf&I#|JaKM%AM+
  // sT,~C~Hvi&","khoA0bqEPAEiElg9U^xW.{PZJns[*|j+B4Da!NbD:{W#$G*1JRj=<J*pV?a#B<EF#c<&kM+>b^3DZy<76;V/ED.rcsP$aS_@
  // Mw9`Gz@xF+>t(8$KayISnU96/d#q_:.YVFI2{(C{%=)HPyr_f","8(jE>Q7AsE{A>WGVq|)4JsuVi3a,rq<?IY{.-zO+AbOv!e->rA@Y]pjF`}4Sx^DgXnIj|f$%+t^GhfO9Iu[jZb","qO@)_uy","[EF%RyKCn!vqE-`&aeORFMGMq:?!x{W8fH|-zrzKvTw3oOAsmVB*;Kc%NI","</^|%5H2d]={*e","!71&qX-*","J}ZgE;O/:iC]$E
  // <P","Z4>vPvYZln=vc)D[X(P(v q3$:t6=_S!bQ&dgd>
  // >#qkof&Fs`^q_nr#~p)[U8et-_.sCl7Q{Ld!QP}tA#2Oq(>7,Nh2K:#RMSmz]h7^j/#>&J$MQQB08MIYOq{{rqF%$_UN$ln3G1Ial8jk","$0a7c:R[/(","|_K:}}NQ:a(g~2Z<UEN.$%r[oI:@`j3-=KfWe`c:s!ipCoTXO%#b=dB9q|U8kAj*i9Tyr2d7X%!kejx$=->1+!5X
  // p=>wF.O/A^qi7V_H*fCmuc#,}^QNe2yx?_N}b&D]q^0 s}|ND(/L","I]l=my]We
  // ","P;n`BJ:P#hwiTfbw,axf8FaNww@gO1J2&m","ChquPpets/z3UFnB6QM.B5<dN9gKDuOc`(Jt.5YlNl>e$XTA@$Pj|$s7TE=I=)^Gh}?-pr2-o=Mfh>^1+k>N?FTwZXjK(X
  // df0ioP8>9KjLYGCW7uVD{[_rBbK3}Mc&d`Dt%FR=:2o*Vqm%n|JUI;Uv:Ma(?-Na|99","<sEeMt
  // $6v+d0|c*1-,_=TBW,t@%Dy5aW-irYJ%1bPJPQPBBM@z&)^i+q$6/;UA4@_(_w
  // L^RdzsWo%-/hZN=G~.MYKdk|QqWCTA}Ck!<x0Qt)Qy,|dr:J$[AsFF1{cg<X*5+0*=zb~(NR@a>_Ej","$9:$ZET$4OICI0=e.ma05p?=}
  // t*FjnY_7Yz{Wt9tUvqWS/PS!}x<Vb v
  // I:?2F^@J+3)bW4g%5<8X!z`*Tnj<#j/>uVS3DMv-dafr0}vYt<;n4;M|s|9g[f?t!HiXE*abwnwb","*^dw0i%?oPsIxJmR,cXu4O,+8F{;t|?lJ#,m->7}cCH.bxRQQCS]RZ@sBt3l^#<HV8aC3/eDG8`3!ucLtf","hm`=&bn0XVutNf2]b`asDuYeF>!p5PGFl`nL_ugj*[<pleH%@l:/A,GQRdpc_/HzXgf?HdQ*h5b?7
  // ++%kcfOks7v.!`#`$#f:C?fOMlY(/_9n2#x=Spd4K@$A`:aWx|:/QQqhEZtfM r
  // nqCws>hK4PC?buvEx/P3``g74L6c}~CV6zNm-au?M>zh]","`,96zd.RBJ/-(4ovT1|v>cN1]!5[K6FnPDNXu&!DJ$R$Ds-pDZ&m&l9H}323I9t@","5,Yy~hC5@c#FLJuaYpq|+TF5C?biN74<)%9sgpscI?Khr6(E7boB[08|*Qn0SXr[mTZ]SNBFP5!6Q=M`$U7xiA]-o?W!MP^L
  // mk8W#.EkhyUbdll.`w2P?P&TgFy{#IbACi-|{:m9ql7w(1xdFG,8r
  // [r$n%{_3(","{MsFm8L;%c`~[V|30Ms.^GGu~gHNW.p#>Sb%G+GLuzQaDD.wmAPtNK1UB=*{$F<.M4^p>Osxtvg1,(}!oY9Ov-hg<i%[dJfV3g+
  // |jE~tu3KU_}}>*/l_=3h F!N<+4-e9jLp5]l6;-ofH>1IW=c_fa}
  // ncI","<h/`(&IUT={t[>#,}U@Eb*T`i","10_Ul/@h7#9oK*ypT|","a8p,|n1o$;xZHhBn5vR,%HN5
  // _IJ>6>iw?lIr5Vy","#S~httEqJU~kLK` P$/e|hPUC","8m3;$c|1amO,l){jBqX8>7fn5ae:2
  // Y=#986^UHw","WbqO2y~zQRZugtA_{HD(}4H=::Y+~g+J;$|w=cT%ttD;6o+%I1OeH5ZiP?puCYEs=LTtT]m9{~C/SiCG$i9E+*|J=[5]XC*QJ@^3$-S]C_2V+!oDN_B[}tuftl2@ZtO6fyIl5oA6R{wO|yw6WV@&Q$rZ","KnekQcn`","t(B}A4TMt3Q2x/t`7o;u+[-f%W10D}ccUF[jn:[l)Ku:[-`aW2k?#xj>bal3*r]",".CP1XwYShJ`+8#UdweiKiVs1@Uxrvyohi0JpUM|]00~f-]u4MGJWMG&Hs+s#_.U","U
  // QFLmldK!%1R;W``a?2x4DzOvki:*T09_`Rx81oeOP!cV>c>Lp#%QldUA;15Cca+$w&=7zM_ie/cv3sn2T%@hwLp4c]q4&_BUaGCpe#&`xK_h0hm--q#Gh]rIZ[wTND7zl?O>{HhZm5iHq3}v7:.}","n|Tmn>](PG#RKljX#!00A%uucF+c0[x*^t)0B.Z}8V{O4<1.@wi;&qJgx_B0lI,/)f(2.wQF=Ff;OcR$d]Ev%7.zM=|XUo-i;@:,j!|tAT9Ij^dP4rAE]7;[FkhFem<<%_-K;YMqCQ3;#_L/6$STnPr1WP!lpf:3n!,A9:;>2g#3ygqiIrVF","&6o<>j#DIYvn?!5Dzz[?eWa,8DOlE=78552y:rGijP8H<v7SThz1bM9reUT%WYS","kEHNA:-;YrSX`K:HP)!i-!u~:|)Z9XjNEw5%y}.Jim1877AP|KyRm=cYlA{#s%)1V{WK9&8{@4V-#J|]?ksTh7lj:bAU8nRt_fg$E^7x?,h#_+ZLozQE>","CE-QRy732%z<UGZw68(`Fb?8,oc4wSd:r$:.RMju(80Mv)E/bU0EMz-O#((9)Jktby([U.s}V|#UTOX]cz3kMxM4gLz:JYWJ_c+z<|%W23AQnC<>7yW7=;$46D!1HokOtRO!(t3[`F;q&.kK6v{.,>]wn7eX","QRNQ.UM]A%JDt","+mBH4rK%:V)H$58$;N+JaFUXeU`(~jE6c^_el_(d(=Qj
  // ry!SxM.X-OvUP|#`$QO=@nN8TAF&s>ihFZ!5C?@nukysIB*6s.mDswM{nj#=p6>)@UIj(ZgMTO>Ki<[ SVLuF/~o
  // VIb","YNH/fuH+KG%L*b*-:alY!?,I)/qdI*m^D2AlL+OP`?0[(9C]v23uP","G}4l-sGQo,`0b 2br?5AJG<
  // 4/vUf(#U(T?b*S#4rDYCG`TGM]xw[{6az%m[)S8B.Xb43fEX2GrH!aP8Fql06O%HJi u
  // |w~r7~:qA?qcy6h{#uUu+f%Gg$o9fGcaLu>D","CQ~y4:Q.#p/|ys></1n5?*h|mTi2hF5N(7S/!?f^Y~D.iXbH#`0+LrsDw%6UxVsTnu=)zadLK%+:f#duXmML/:;GX<dr=yE4bZDBuL/lN~)-`^w`%{Y9v{vJf~Ai(-R@g;FM}Ku(QN45k4Svq^,0mp65jI2q<Z7T@Mu=T2:#Blb#u]Bq*","_&!.2=[Ba
  // !r~?l_+gJEtBogGg|>N<KHj}S:N[HR<Fv-N)7:Tf3jz9)C:|}c%[9joF[>~]x+vOL$w8U^OE_ym+me8K!Z8en{[U2!abY;Dfp
  // &y2O]re;gp03t>AXUzg.
  // NMxxWHpu#[V]Mik%;^rY+sp44l","8c.QkT12Z?M8~p]){pPqIvG@%46b22ccaksR<x^ZEW[4}L^48XLgjuUd
  // Nm!UBPq{uJR.GOD6]EMxoh&
  // :[_LPC^RjGpgKXx(J6_lW`i;;SBC*%XPOhLV9","%/x-3bQ0^6tcH-?GP2C0h[[sbx!&w6K@ mJ(!J8afDK#dZ1]ut3c$
  // `p8Qy95{0V*Q23)}UMBc)<rw-W@V=(4$XrB}iv4oH`V2(e00$1f<>r?LTT9pWE{F}mjTmj-,SM75Kh>d&UASLYh0k,Xbd}-P8B-K-
  // 9(dp(`OA 9
  // RXfiR+;*mB4Xzfzs?{(oXbeggc`","SB4tzWx`cKNZaCoVqd%Z*klLd+QI,eefp#{e[Z@GjMw81/GCf~T;g`r!1=NrC@7(8|Qsoh|jTU$8/gFM.3/4k#U8)FD<sBzAMLtg-};K0)6k@},`
  // KP:Ve@!ce9MpK7Yhts.B%ocf;!vF]F<h 2VL!n7pB&J","F tD <^7E O!b3e{>e]DPJC8NXnfnkVBbS>{r0DpLDW]f
  // fM+A=qgUHr~]aWd=f_no3xf/jG0.L;!{5|0#9>=ZYQ&sr@Z88pZc@:cmirJD8s5$J<)^)G{p<Rt[nH;!SoOvJ3;>73jfh-_J_hi@A@$L~j!e?M)AB;j8Uh{Twk#","QAx2d)Y!R7o3SCRiHIEo0e3S.n2kaID7%yFq5nLBh8R&%*ekoeLSRDIXYyo>Jz
  // q:}k{6}P[p(+k(PyonU516xuT_tNm{eCBc7v[#J>&AR,S[3|0nK","IAywu9)oQ=$S71%XR5sI3LwB>{YbZS1wKSD","F4dxr-_&","E1eMIy*#SlA
  // q2S+s,1ZR!}R!wD5jc+","c7=7f%L}d!Jogkt>}8u$kxNvW~x;ayS<l>?lN#{-@}{wtRYlF7Nyo-enX43ZT),]2}bkRE2gp
  // .bo%`7EpoO-dbG(5-[LuKhg=~sJ2Phh7
  // 1o$#8Z$/W5;#%9Ib]TWKVpUThh=4BVC1S#cV9TD5l~7>fIvx6Z]VPOx:gzO@_h|C,u
  // nLZ*`S>]Qr4xmFRz4bp*A","|78!Ka.%oIC[$iO?(e$((I:X9oHtn*OTQn3~)P*-%9qF-?S1db2grwo`Yl=.rBmpE3iG^MT$|?8S#x(.2o#_I)S1
  // ~,p_ESzD/d0dTq2u
  // @sDH5;p3]8Z]0)pY216StBec[:T)lYKm?2kg&Jyw:CWQNQK;v4wp[z@Z9aA,OVv]?L476@5ciXwD[JgHglTuy","U@1A2k/J5So8JlRko!fK!QGj9l/7fO6Y0xffoJiN+!YvU_m^_TMhptnO!dOPHZHRy:O2=^|aV5P9cuPi=>az-R>^h-3In~#z/3","REXft+awOkzbvh=p=Kq%$Yb5o^2eg|Y>bm/}h&O|Rigi6*koZBUvT!yBKPmE&]m~*D1<Woh]yJn#h~xw-QJ}R*[m@yOt}i<%~mC
  // o#=FC%A#hl;`v,--KMFR$_nX4V8jSU%)un","
  // >|%+D(5?s[z=o3Y+bx`q:|Db:`M#QTT{-@M7=$IMLP9hu)M>fJ(F3?AB&7NZttCn-JmaOF(v@[{Rf9ed~zuAk`sxjZr>m7W
  // ","Tdh2ox.h5hF87+WLSPTX3b13XzEQkjw]GJkPt(_Pv;ZG7bx`[o}0dv
  // YTmUqjnuy>e]:hkL&l{l_BH9k_56F?*zqzzI49rM~uB[FyfMAW^e2v/[l,g/^1YU#1|I[tf|V2BaPO!;z+t9Jdt9/^to.PYJMjM.}/WH*7Cj}+","#[R[zjdO|q1B*4wk%?A7&mH+&>U?G`rP&a*$1~VF]K2Bj`SRz/DU4scLzf0f^S~OP^<B>=?Rzp&l@3g)q^W,X2@%b2GqV>QMS=f$,DU#","",",[*D,^=4fJ7(-Bu&VJ4rZ^bGQ:5^@LyiV6%b)coR8*hO@","zlM:6RQ=w?
  // !Ey![zkV#3vvRKRQ4gsSF/]%^&&CKs:-rS,Ei!>Ia1lud>%7%`el;OrSPKtXc0n%7F?bEmp}31%bF!`OYF{QSA/F)!5za#<;Brw:)SL)Ca?(AWcbj8P61E7p0","k.!7MIVi_PKxIOJOF}Z","UThEK40kz8^Bq->Tkf5Y&2SxW>/uut<H0&NPt/0>S7[c$t*ZHxE6z+-&[mt@","d7a,aJ_n-SvDS?u77cgw~F&~4eYmbz.2j(>
  // ckHamM!|4jF?bR2,Db%sk477emQxN
  // lTbef^7<skc;KP)4wLqa5b3OFf7~c3-Zf/DKbjv[/|Pn_Oa`+AP5[OsKjeF|j!,]3a,}O=a`Ln6M=d{=ByO5l5;eplU|LYO#%<zY+]qDgWrz|H`;b^2",".XfX{>lk+2mq6/m7O*Djep/S8$Q5SN#%GT5G}Tveh&cy^L>^","[I[5-.1Re31o}ytQam!<0^,@2y.Gn[CwCmi{hx^ktS@[<odp88*W1XO&=tyaqk9lW[6C@DSW9PuRR)]Uw#WV!JL(|XEiQ?q0OuuTz-,_I.tB,,$MhyGvRsQXMY@QOM0xEvNAwtmAXpi3!FBKoy8D,m8=
  // /ex*BK]=s}#M}mV(6o3~>[(1l6+dtt0z} ","[ppFl6P~mw`zW`P-[*~>uUj*g0*xqM>$,Q0VX~ACwO
  // $9q}65]bpSTf(:m>o)|(dN?5gK<;ml}8ma]Jf|@)TIbI@4HK{|2$/q6M>yE+/tHt%*ullD/T:Gk2B2},{q.Lq7tFK[ehxgA5*:#a)s,D0Gv,%u84","DET]alGR~Jc_mi9$%G0nYHr;0P9Z1L/gqaz18pYl*|<3,*=
  // 8J}z/Md$(+3{Z-Fr5#`~ 7/LrHsaw7[(Rao&,#~G#Q)&L6e-}0*`<8Wf>#hrC6Gz?Iy5?{?(O5$GLHs4mcEJ
  // ,+&z0@2*7{rd`?<sA$Ss2Vh5+vD.Yq+i}P>(zA>z_.0X#_-&!C`","VVOl=D!/P_sgg@2tZFDqZ@3!puEE
  // 6l[EI^{_da]v<59b1w`BlPGq(PJ|!eA1G9A[.n$VE6?,k}vgT;]f%}N{I
  // uyGkB5L,rIuz$-Rj!~LW_Kj7F-MX4_0V$06!+jhE-(","XmZ_*)$)WZ+Hh/H3h;2e6j7$#C)XaLAOU:us-&bZ]9gZFw@ZQVarI3*}Lk0))58E1jAH)K*,gOK?m3AwaoixUkhW>W@P${F%(l[=cryDj:
  // #V,hCq.^_L*TfR-",",<J?3y6|+/F|wc#h6<vXDq8*kgBA49lUy:RKB9v2Il","p5/+33X)Ih0wDNh3;:*xdo|hl3f2Lbkl}]|%YT!uAD@","?2W6}|EtYe:PC{n2)CYLp7k9X2^bTSU,&1A51!>f}]=i*~}!1=2TK/t?0q6qDH&LK8}R{KjW)S4?4+7YAvv:F
  // YwU8k]_FsU|+PbS1FNexO;$q&3!i@Ff)T~WWj.0V,RX h$BR;J04~t#ciqxrrA)P>O~J59$L|vRya`G?$bTU4Im{1i","FT
  // -ijub`jp&>eL#D8Nn}<{$CxFqOjNsyh|^coCkOLT7:u!p[b10:I{=|LYo&-#9Rkx/bsE[ZEJ~6S?$iE!eeJ%2Tku;lS3~|k-WZY_fN-E<XuV`z-VwHP@T+`5@peOec&S<0?[Cq:#f<>n15W_+(`V2(f9}px0jurmhZs>0&~AU3`^9musA}ufg_YM.!g*lDoqF>","oY]v;7wu*<xtian@^QsKI!$+(kP51jJ+Z<&teY2
  // vlb&nL<Aw?ma MbM%fx{=aIjzO:[!t!pKdc-~9JBeS*?};ur.pLR/=KM(42cS h@EHGp1}`h@Jk8=?(^$YWN>Y#fev","Ii
  // au6Q973UW<*gzq%-Rb[p)R7ekg;A9rLr0xJm~(AR>%4YG8~,p9jMzp/ Ui:.0VSYfxltb%3]SZx]^1lMQ
  // XtbWH)0l#l@J*70.i+%v>BWP0-u6zwEO?YAM%w<Af$[2Yq{,g{UWIa9Ay}b#X#;RUTHOh!e$9K.%T3BPT>~[*FDP>},b9
  // jZ%vii#8*W&cj%","+4
  // Y+`<-jTc&(B/QbU.,.q],eLmaiDCs^KcO!dcxE6Cz%*q<?445{7)lF*w+4s)N3auE##!/7b?cs9`(.qpn+We)jA+%Tm/x~e:
  // NqUdd[]6~$j`{pZD@qB^OfI3<|s*U;~6T9:q>lop@PYT=.WB,U*d5>]*ewS%WB,/gl6.48f","$V/Ff7[,;4]8q:i4R5Q^TEe)i@BhZ#qq-iq~$Sy^*Zp+Y&-h:}hWxP@TCd%C!Vq*6IWVyaQ+OMjH=Nf%>V@e7U,/hP;mg5B~1r}EdykyR
  // nL{8{w|T$6OI)`%;JHdcQ#Lf+aEDOz{(=Ql-.3dV=~*9+MR,B%qqGxN|<ZdJ,Nk)v_QoaAXxDGjasD#Qbu?RVk/&","Z65.?cd@k!K%%r?]wS?!IhW^4UAt&?G0Mtpc+obWEN3p;D:0(ao)Di{>`%,/d4rJD):I3xy","/:#[mbv+]eb#6oV93%cw+q}NoGqj)","Bm<s.X<j}2W*9=kMpiSO]f$C%GJ*[2G&m$PeYtEf
  // zHv(j&","xn6f4oET!}.f5u(80*(uU*^smzNw!mvP[r1eqirO:lS !Z}!$8-6B
  // 7#11<:zl","q~","cspUgYsd#~%kf:VPcfEudZJcv2
  // %>6Rp<GH58pX8[?S5","|C*?s_YW~PGp96#q-;4?dkzy4IB&~%YN#kk5#,!KDW%u","8DcH<=E,R.+.QZB>:^xD4U
  // 3Ubckk?bO_v-qD<Ij9H)}C*GmAt~(J$S-G#=z",")J(hy;}{#pEJO2WCT?%t[:pmd^I@Cyl3c:)]pT","6lPs-zQ`W`oxv5Lr_xYt&tFVU&J/[>Tf6zZeha$6U`z!%!zs9/t},S-MbxF^-~,EQ=d1<eCF-+)MyLMeH9yvZJ{h#i6z/:ITx@S:RRlreMmprA1vUMJY!S)p,]#etmEM<L!A_n1^s4","w!(l`^[N#2#lLO{C0C)(qVn4BS6UKc,[5:Iy@MO(I%bP7~v7Ik]mn^m4vbIW!26`=-w","Qn}w3A5l_ckq1=pWSNUyma_Dn;lt9&Bw$?4(a(dK|8*V.gn#?P:G>gc8E|&wYM}otb?DSC<L9/#HW<u+k>E8[91<@cJ
  // $sQn,,v#X{`nKPL0@xL9VU[,{AU|lE_:R9;I0?+Q_LLnP`/hT7/4/Vjltg,(f/Wrl$p/a","%f8q9sIZb>xBtuWDIhp_N%28PdaoHI9q{1","!tVXgS(yEG~biN;809`{_6(2PBCY)xUj1+t._=-k#hQfwc8$Q;-dUhfkN_wslV);gZAF(}=t7!9KS4+&R{!SCp;-JPY6aH2iS}t^uk*VVjg~{i!9;[!ATPtt!CN~28D<cfAAczB=:=2;eW:qZHU-nB<2616f-u?:N;v`o",">(EuvA3%94qJ;-h`e47W|X<K","I
  // KOIC]kr`B!X0{9tHk.#MF0mdR~.[s1.5B<@vGr!@p7L6~dTP,L3n.=Z(2vnH,d[W+S*c)","sA<L20jG):muYSzT
  // us-zi.F4p/8sd Fci^x^t,<k[#6ZR0/r-,k1;{nD0bAy>s7HVfIs/Kt):Qn?&VC@DE{}F-}5y)YOv<W`Bw
  // IZtM:*henr@)z/3$4;|X/$}fE+1$98k1RI)L)1>4qy@n*Zlv8zi`K","f(3Emf^Q.SScuzg@dtJO?MM5,}xT^;i1z`0Z^L4e=<k)SCSP<&SNj|QhH<=k16)qS@$S0JZF$5<|JuPYboe","`X@pnZ8VwA6V&a&wBrf=aYD;c=rIR9wq/PeN3c#3$Z!xpek`W|wMT*tP?d0","bu*@N_`!AiTo)yH$C,e|4rGQpc5]Fj[iiTNa;t{v~fPa$*v8S24ejJ^,Q_1
  // xk5i^BdF","fqj3=8R_5@3fQ;5N{ZgTHmX}5LJn#d7< z^xDMv4 97KlTX#~csp9xt~1t_m
  // 3D[0nT(i}lx4>[FI4DRU,^|h/)P2ST3sx;$,L3<QnV=Vq>oTSI~VZ#45U
  // =,3z3=s0$vEC3brHI=|",".vY2w,F&wPW/ty~N}h}22&!c*i=O=bqBuURz/hz7d?-{uutZ=5[il&,?}w46re4@cKFrgpwaCnp_b
  // 9ktj
  // a&(lg&f/pz},Y4RA},ghIf]adpYC</MRlN8#hAx-<=@e;uw;~H3|(^)rQ>S:H&9z7","9_Ef@st3i[hRV7AI`S^SCdSM4P-7g9&ab2h&8)z}8H|kR1@dNHy8+gg:Vuh|}v
  // FT(iaB[TpVrz5iK?}B<;5v^+/{r(8WK)X@aoPFz)#NM,WNnki"};
  cout << " size: " << strs.size() << endl;
  Codec t;

  vector<string> out = t.decode(t.encode(strs));

  cout << " size: " << out.size() << endl;
  cout << " answer: " << endl;
  // for_each(out.begin(), out.end(), [](auto x) { cout << x << "-"; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}

// ["7YJ}-fN(znA9^cKSX\\\\|J3zl[qW}$B&GJFR","&eIecW~U0M@4EO])MrqU7b;nOm7vEdu*!h4@zSsKvl_Z&wm9p}mgNF]dPS)F!IjJ~,v$Lx.`sEs(F8o_U);$`=bp(J)pU|1tm.~KE]04PGR`0(BBT`n&J~1JQQ?cU4NKj1yM
// yO6N0SUDopz6DXYFZ<Md6_ZA-",".S2^>b8e!*cv()$QDzgG~Opv=Bymb;e|<$:)1F!4,^@?Oykw!8=|nIegX&<4c2wm?^i,&ZuYNHc4&)-(5P4$={aglb
// j)]/]^vALm/=2AK,|$|ohH pSE@-TUW8YQj9?ZZ!.TB/P_i(wFF!@6,Nz;(0TjxYV~($","c?jT
// 0YpUi?{mgPSC=AA.NEE5F#/mI;n!XOs;>7?]27r7Ps//LSSuL5T)8@:W*?pd>XgmBr%ASAV$T%H{,etmdAzQ3n,O$hwqj,*Zd8mHBdx@b)Ku","0<79@*oHGjZ1msv5@<xe<HQuD}*WwFmN_1]z-o%GV435iNm&;;``O5s7/F<|_wxQm;nfmhX@`,DjNv}a,H}=%.#:}##:}z^dvAX{jqa[RP8]Y.(I$W=[N&EF_f]~25","4Z^99$WH$p{}dc%jc!i+j}1(z29)S2*$u&eU!PpS^RQ0@yzQ^z?fG!NY]veF1t^Wp8{(ct7qj}
// Hy{*a=qk[!","AtR`/B-fn.mW =+HfSr-^I5o+hsO|Af,g&ir4K
// xID>/x[&#1R+ww,xfNj><q_Wt9-C;)7mBOFZP#)OnyMO-ouOeu}6M#sHPw~d[s7p-5NZ,W~uO,YGi<nxiZD8L@)Lq>P","pHE?DxH9yL|M/^n#>rS!1hP!rq)((=$O:Jwe92%MWWkUFTuzKw4pbuli8)D~*kJI9]3DNjZ:=N2t?Y(
// m]Ofl!&qjN-fZ2)6<[bA<I bhG.~o|2x8`kN|md lnmo&B]!^,.j@F","3=sk !uurPo+v{#jR
// wOJ@k#a#V2<>m_D9-k6Z",".1NV_|W5#90Ki(5IJz**Sy0vF2AeyRRsl[<QAI`kocN#fWVc!
// z3q^B8x.c)*.XnZ|@%#.o3Ht}$-THVCmLl_k;VOa~7~fU87=R%q$ISf*<B`H<iA+J?N/fH0r`qq_>]!#?T<_(#^rr{=5.u@7","2(Ol%(uupQN`eK&>8Q~h;}OTn-(YBX`bTvcI<$:7[BpE,z
// yFJ3Ec;N%Cagc6ezBLa#.nSgglh9V$, |5i$vi9XC*_%<}l5$}SgX)SoMiD%4kuxy|9HT<J7
// 4Y_X",":+i}V$KjFw3j4p7Y)f!0_Lg?GZDbwo_6Eq^:3T[pr-OJ55yb2=z&C+N<<?I|k)/s$=)5.ULEs=L(gfC-z0:Sn:3WaK?n*~VecJo[0Xn
// lf(]Q%HP9H<WF.m0d]qJ2?p.<BjQ.?5hV>9<1mJu&U+Nv)8E?%`S,SU2kOau`X[kfD-Q.{&~20~84nf_/7Af!L}U?g,S|","omF?S`lqqq/jAw+aO8VG=9+_!~@k7I[OQpdJG^4svN+FMsXpSox+c09`KumhnIumnn","NWwQ#k)&`bCTyKZ(EeU5-qAsB7i>21p$L[IitG`,_g&
// 7wYeTCgJ F~:K?/cw<X+?1#!7NxXF#=;&OO6GDlLen&zoctQ0%kxSD ","ul(B9[>WBC5uFdoO+m
// mETz,Q#2G?sRTbF}K`o^|zU}8?_+ZoxP6XTE","Y3$Y3zu!1=-7
// r.@pppnq0b^QUHxVsE4Dg4fX4J[BpTl.!#f4#19X),aYKzrfS/ZjK[,N}
// (p%OWr98mB7hv,;swc>hD!{h:{q!h&W","u#|S5ub3F{^+8]GO@Mp<ZIJ[<8QpNopR9h[Q<fj]k>dGRqzid%`<-/v];Iv6p--rq/{%4zCyxSp9H6
// P?VATxc-@;Hu,flzaye197>YP?a|C?5k8R&","+D~Sf9TDZ-3)3]XML8A3@-MW9/dH4S~0~:9LK*9ecC8B*KTR2]5P}Q>E?iIk/YGZ1zHz]]$G7R$Q+;{TNmh@/$`>BHW1CRnQBh#d_<OXq[LtD^}7avl.yR=b..[naI{q;vK8CrZ1IT&v[g%%vg7~|/+$}
// F?=Mq.>?BDBCteX4@P:7@v~LNrxm$T)CxWc3&B&I>k.","HsV|~uOdxF^lo{G]}EZ_V&/bu-7FH-TN8!kUP&{uvy}:NJA@x]Ghbc2E@q4(5a|[aP6LMMLuS08@Zt+I$ZV.p`82p??jzF&Z:a$x@d-#K(;;4i2
// :bA1M2{60n+sMJDE&gM{}]g.Jy6.piY2#?K7Ur2wAX6T^!xfb","?bcmb~Aw(Rxt|Vk$_afSn8#HP.G0!:;wQgq=1
// SDQ}TCJ1`5%`2HO$8]OP31cG,bI+Z6ELxg<$;F#d`<trTLm!kUR(BJcLI8`iSrt&3;jBZb]1*hlne||e|Kv Lr)
// A{u]=MBH27Yl*^?tWXEMyRA1N}}uGVZ%?S)Jy(_B]o=vpf&I#|JaKM%AM+
// sT,~C~Hvi&","khoA0bqEPAEiElg9U^xW.{PZJns[*|j+B4Da!NbD:{W#$G*1JRj=<J*pV?a#B<EF#c<&kM+>b^3DZy<76;V/ED.rcsP$aS_@
// Mw9`Gz@xF+>t(8$KayISnU96/d#q_:.YVFI2{(C{%=)HPyr_f","8(jE>Q7AsE{A>WGVq|)4JsuVi3a,rq<?IY{.-zO+AbOv!e->rA@Y]pjF`}4Sx^DgXnIj|f$%+t^GhfO9Iu[jZb","qO@)_uy","[EF%RyKCn!vqE-`&aeORFMGMq:?!x{W8fH|-zrzKvTw3oOAsmVB*;Kc%NI","</^|%5H2d]={*e","!71&qX-*","J}ZgE;O/:iC]$E
// <P","Z4>vPvYZln=vc)D[X(P(v q3$:t6=_S!bQ&dgd>
// >#qkof&Fs`^q_nr#~p)[U8et-_.sCl7Q{Ld!QP}tA#2Oq(>7,Nh2K:#RMSmz]h7^j/#>&J$MQQB08MIYOq{{rqF%$_UN$ln3G1Ial8jk","$0a7c:R[/(","|_K:}}NQ:a(g~2Z<UEN.$%r[oI:@`j3-=KfWe`c:s!ipCoTXO%#b=dB9q|U8kAj*i9Tyr2d7X%!kejx$=->1+!5X
// p=>wF.O/A^qi7V_H*fCmuc#,}^QNe2yx?_N}b&D]q^0 s}|ND(/L","I]l=my]We
// ","P;n`BJ:P#hwiTfbw,axf8FaNww@gO1J2&m","ChquPpets/z3UFnB6QM.B5<dN9gKDuOc`(Jt.5YlNl>e$XTA@$Pj|$s7TE=I=)^Gh}?-pr2-o=Mfh>^1+k>N?FTwZXjK(X
// df0ioP8>9KjLYGCW7uVD{[_rBbK3}Mc&d`Dt%FR=:2o*Vqm%n|JUI;Uv:Ma(?-Na|99","<sEeMt
// $6v+d0|c*1-,_=TBW,t@%Dy5aW-irYJ%1bPJPQPBBM@z&)^i+q$6/;UA4@_(_w
// L^RdzsWo%-/hZN=G~.MYKdk|QqWCTA}Ck!<x0Qt)Qy,|dr:J$[AsFF1{cg<X*5+0*=zb~(NR@a>_Ej","$9:$ZET$4OICI0=e.ma05p?=}
// t*FjnY_7Yz{Wt9tUvqWS/PS!}x<Vb v
// I:?2F^@J+3)bW4g%5<8X!z`*Tnj<#j/>uVS3DMv-dafr0}vYt<;n4;M|s|9g[f?t!HiXE*abwnwb","*^dw0i%?oPsIxJmR,cXu4O,+8F{;t|?lJ#,m->7}cCH.bxRQQCS]RZ@sBt3l^#<HV8aC3/eDG8`3!ucLtf","hm`=&bn0XVutNf2]b`asDuYeF>!p5PGFl`nL_ugj*[<pleH%@l:/A,GQRdpc_/HzXgf?HdQ*h5b?7
// ++%kcfOks7v.!`#`$#f:C?fOMlY(/_9n2#x=Spd4K@$A`:aWx|:/QQqhEZtfM r
// nqCws>hK4PC?buvEx/P3``g74L6c}~CV6zNm-au?M>zh]","`,96zd.RBJ/-(4ovT1|v>cN1]!5[K6FnPDNXu&!DJ$R$Ds-pDZ&m&l9H}323I9t@","5,Yy~hC5@c#FLJuaYpq|+TF5C?biN74<)%9sgpscI?Khr6(E7boB[08|*Qn0SXr[mTZ]SNBFP5!6Q=M`$U7xiA]-o?W!MP^L
// mk8W#.EkhyUbdll.`w2P?P&TgFy{#IbACi-|{:m9ql7w(1xdFG,8r
// [r$n%{_3(","{MsFm8L;%c`~[V|30Ms.^GGu~gHNW.p#>Sb%G+GLuzQaDD.wmAPtNK1UB=*{$F<.M4^p>Osxtvg1,(}!oY9Ov-hg<i%[dJfV3g+
// |jE~tu3KU_}}>*/l_=3h F!N<+4-e9jLp5]l6;-ofH>1IW=c_fa}
// ncI","<h/`(&IUT={t[>#,}U@Eb*T`i","10_Ul/@h7#9oK*ypT|","a8p,|n1o$;xZHhBn5vR,%HN5
// _IJ>6>iw?lIr5Vy","#S~httEqJU~kLK` P$/e|hPUC","8m3;$c|1amO,l){jBqX8>7fn5ae:2
// Y=#986^UHw","WbqO2y~zQRZugtA_{HD(}4H=::Y+~g+J;$|w=cT%ttD;6o+%I1OeH5ZiP?puCYEs=LTtT]m9{~C/SiCG$i9E+*|J=[5]XC*QJ@^3$-S]C_2V+!oDN_B[}tuftl2@ZtO6fyIl5oA6R{wO|yw6WV@&Q$rZ","KnekQcn`","t(B}A4TMt3Q2x/t`7o;u+[-f%W10D}ccUF[jn:[l)Ku:[-`aW2k?#xj>bal3*r]",".CP1XwYShJ`+8#UdweiKiVs1@Uxrvyohi0JpUM|]00~f-]u4MGJWMG&Hs+s#_.U","U
// QFLmldK!%1R;W``a?2x4DzOvki:*T09_`Rx81oeOP!cV>c>Lp#%QldUA;15Cca+$w&=7zM_ie/cv3sn2T%@hwLp4c]q4&_BUaGCpe#&`xK_h0hm--q#Gh]rIZ[wTND7zl?O>{HhZm5iHq3}v7:.}","n|Tmn>](PG#RKljX#!00A%uucF+c0[x*^t)0B.Z}8V{O4<1.@wi;&qJgx_B0lI,/)f(2.wQF=Ff;OcR$d]Ev%7.zM=|XUo-i;@:,j!|tAT9Ij^dP4rAE]7;[FkhFem<<%_-K;YMqCQ3;#_L/6$STnPr1WP!lpf:3n!,A9:;>2g#3ygqiIrVF","&6o<>j#DIYvn?!5Dzz[?eWa,8DOlE=78552y:rGijP8H<v7SThz1bM9reUT%WYS","kEHNA:-;YrSX`K:HP)!i-!u~:|)Z9XjNEw5%y}.Jim1877AP|KyRm=cYlA{#s%)1V{WK9&8{@4V-#J|]?ksTh7lj:bAU8nRt_fg$E^7x?,h#_+ZLozQE>","CE-QRy732%z<UGZw68(`Fb?8,oc4wSd:r$:.RMju(80Mv)E/bU0EMz-O#((9)Jktby([U.s}V|#UTOX]cz3kMxM4gLz:JYWJ_c+z<|%W23AQnC<>7yW7=;$46D!1HokOtRO!(t3[`F;q&.kK6v{.,>]wn7eX","QRNQ.UM]A%JDt","+mBH4rK%:V)H$58$;N+JaFUXeU`(~jE6c^_el_(d(=Qj
// ry!SxM.X-OvUP|#`$QO=@nN8TAF&s>ihFZ!5C?@nukysIB*6s.mDswM{nj#=p6>)@UIj(ZgMTO>Ki<[ SVLuF/~o
// VIb","YNH/fuH+KG%L*b*-:alY!?,I)/qdI*m^D2AlL+OP`?0[(9C]v23uP","G}4l-sGQo,`0b 2br?5AJG<
// 4/vUf(#U(T?b*S#4rDYCG`TGM]xw[{6az%m[)S8B.Xb43fEX2GrH!aP8Fql06O%HJi u
// |w~r7~:qA?qcy6h{#uUu+f%Gg$o9fGcaLu>D","CQ~y4:Q.#p/|ys></1n5?*h|mTi2hF5N(7S/!?f^Y~D.iXbH#`0+LrsDw%6UxVsTnu=)zadLK%+:f#duXmML/:;GX<dr=yE4bZDBuL/lN~)-`^w`%{Y9v{vJf~Ai(-R@g;FM}Ku(QN45k4Svq^,0mp65jI2q<Z7T@Mu=T2:#Blb#u]Bq*","_&!.2=[Ba
// !r~?l_+gJEtBogGg|>N<KHj}S:N[HR<Fv-N)7:Tf3jz9)C:|}c%[9joF[>~]x+vOL$w8U^OE_ym+me8K!Z8en{[U2!abY;Dfp
// &y2O]re;gp03t>AXUzg.
// NMxxWHpu#[V]Mik%;^rY+sp44l","8c.QkT12Z?M8~p]){pPqIvG@%46b22ccaksR<x^ZEW[4}L^48XLgjuUd
// Nm!UBPq{uJR.GOD6]EMxoh& :[_LPC^RjGpgKXx(J6_lW`i;;SBC*%XPOhLV9","%/x-3bQ0^6tcH-?GP2C0h[[sbx!&w6K@
// mJ(!J8afDK#dZ1]ut3c$
// `p8Qy95{0V*Q23)}UMBc)<rw-W@V=(4$XrB}iv4oH`V2(e00$1f<>r?LTT9pWE{F}mjTmj-,SM75Kh>d&UASLYh0k,Xbd}-P8B-K-
// 9(dp(`OA 9
// RXfiR+;*mB4Xzfzs?{(oXbeggc`","SB4tzWx`cKNZaCoVqd%Z*klLd+QI,eefp#{e[Z@GjMw81/GCf~T;g`r!1=NrC@7(8|Qsoh|jTU$8/gFM.3/4k#U8)FD<sBzAMLtg-};K0)6k@},`
// KP:Ve@!ce9MpK7Yhts.B%ocf;!vF]F<h 2VL!n7pB&J","F tD <^7E O!b3e{>e]DPJC8NXnfnkVBbS>{r0DpLDW]f
// fM+A=qgUHr~]aWd=f_no3xf/jG0.L;!{5|0#9>=ZYQ&sr@Z88pZc@:cmirJD8s5$J<)^)G{p<Rt[nH;!SoOvJ3;>73jfh-_J_hi@A@$L~j!e?M)AB;j8Uh{Twk#","QAx2d)Y!R7o3SCRiHIEo0e3S.n2kaID7%yFq5nLBh8R&%*ekoeLSRDIXYyo>Jz
// q:}k{6}P[p(+k(PyonU516xuT_tNm{eCBc7v[#J>&AR,S[3|0nK","IAywu9)oQ=$S71%XR5sI3LwB>{YbZS1wKSD","F4dxr-_&","E1eMIy*#SlA
// q2S+s,1ZR!}R!wD5jc+","c7=7f%L}d!Jogkt>}8u$kxNvW~x;ayS<l>?lN#{-@}{wtRYlF7Nyo-enX43ZT),]2}bkRE2gp
// .bo%`7EpoO-dbG(5-[LuKhg=~sJ2Phh7
// 1o$#8Z$/W5;#%9Ib]TWKVpUThh=4BVC1S#cV9TD5l~7>fIvx6Z]VPOx:gzO@_h|C,u
// nLZ*`S>]Qr4xmFRz4bp*A","|78!Ka.%oIC[$iO?(e$((I:X9oHtn*OTQn3~)P*-%9qF-?S1db2grwo`Yl=.rBmpE3iG^MT$|?8S#x(.2o#_I)S1
// ~,p_ESzD/d0dTq2u
// @sDH5;p3]8Z]0)pY216StBec[:T)lYKm?2kg&Jyw:CWQNQK;v4wp[z@Z9aA,OVv]?L476@5ciXwD[JgHglTuy","U@1A2k/J5So8JlRko!fK!QGj9l/7fO6Y0xffoJiN+!YvU_m^_TMhptnO!dOPHZHRy:O2=^|aV5P9cuPi=>az-R>^h-3In~#z/3","REXft+awOkzbvh=p=Kq%$Yb5o^2eg|Y>bm/}h&O|Rigi6*koZBUvT!yBKPmE&]m~*D1<Woh]yJn#h~xw-QJ}R*[m@yOt}i<%~mC
// o#=FC%A#hl;`v,--KMFR$_nX4V8jSU%)un","
// >|%+D(5?s[z=o3Y+bx`q:|Db:`M#QTT{-@M7=$IMLP9hu)M>fJ(F3?AB&7NZttCn-JmaOF(v@[{Rf9ed~zuAk`sxjZr>m7W
// ","Tdh2ox.h5hF87+WLSPTX3b13XzEQkjw]GJkPt(_Pv;ZG7bx`[o}0dv
// YTmUqjnuy>e]:hkL&l{l_BH9k_56F?*zqzzI49rM~uB[FyfMAW^e2v/[l,g/^1YU#1|I[tf|V2BaPO!;z+t9Jdt9/^to.PYJMjM.}/WH*7Cj}+","#[R[zjdO|q1B*4wk%?A7&mH+&>U?G`rP&a*$1~VF]K2Bj`SRz/DU4scLzf0f^S~OP^<B>=?Rzp&l@3g)q^W,X2@%b2GqV>QMS=f$,DU#","",",[*D,^=4fJ7(-Bu&VJ4rZ^bGQ:5^@LyiV6%b)coR8*hO@","zlM:6RQ=w?
// !Ey![zkV#3vvRKRQ4gsSF/]%^&&CKs:-rS,Ei!>Ia1lud>%7%`el;OrSPKtXc0n%7F?bEmp}31%bF!`OYF{QSA/F)!5za#<;Brw:)SL)Ca?(AWcbj8P61E7p0","k.!7MIVi_PKxIOJOF}Z","UThEK40kz8^Bq->Tkf5Y&2SxW>/uut<H0&NPt/0>S7[c$t*ZHxE6z+-&[mt@","d7a,aJ_n-SvDS?u77cgw~F&~4eYmbz.2j(>
// ckHamM!|4jF?bR2,Db%sk477emQxN
// lTbef^7<skc;KP)4wLqa5b3OFf7~c3-Zf/DKbjv[/|Pn_Oa`+AP5[OsKjeF|j!,]3a,}O=a`Ln6M=d{=ByO5l5;eplU|LYO#%<zY+]qDgWrz|H`;b^2",".XfX{>lk+2mq6/m7O*Djep/S8$Q5SN#%GT5G}Tveh&cy^L>^","[I[5-.1Re31o}ytQam!<0^,@2y.Gn[CwCmi{hx^ktS@[<odp88*W1XO&=tyaqk9lW[6C@DSW9PuRR)]Uw#WV!JL(|XEiQ?q0OuuTz-,_I.tB,,$MhyGvRsQXMY@QOM0xEvNAwtmAXpi3!FBKoy8D,m8=
// /ex*BK]=s}#M}mV(6o3~>[(1l6+dtt0z} ","[ppFl6P~mw`zW`P-[*~>uUj*g0*xqM>$,Q0VX~ACwO
// $9q}65]bpSTf(:m>o)|(dN?5gK<;ml}8ma]Jf|@)TIbI@4HK{|2$/q6M>yE+/tHt%*ullD/T:Gk2B2},{q.Lq7tFK[ehxgA5*:#a)s,D0Gv,%u84","DET]alGR~Jc_mi9$%G0nYHr;0P9Z1L/gqaz18pYl*|<3,*=
// 8J}z/Md$(+3{Z-Fr5#`~ 7/LrHsaw7[(Rao&,#~G#Q)&L6e-}0*`<8Wf>#hrC6Gz?Iy5?{?(O5$GLHs4mcEJ
// ,+&z0@2*7{rd`?<sA$Ss2Vh5+vD.Yq+i}P>(zA>z_.0X#_-&!C`","VVOl=D!/P_sgg@2tZFDqZ@3!puEE
// 6l[EI^{_da]v<59b1w`BlPGq(PJ|!eA1G9A[.n$VE6?,k}vgT;]f%}N{I
// uyGkB5L,rIuz$-Rj!~LW_Kj7F-MX4_0V$06!+jhE-(","XmZ_*)$)WZ+Hh/H3h;2e6j7$#C)XaLAOU:us-&bZ]9gZFw@ZQVarI3*}Lk0))58E1jAH)K*,gOK?m3AwaoixUkhW>W@P${F%(l[=cryDj:
// #V,hCq.^_L*TfR-",",<J?3y6|+/F|wc#h6<vXDq8*kgBA49lUy:RKB9v2Il","p5/+33X)Ih0wDNh3;:*xdo|hl3f2Lbkl}]|%YT!uAD@","?2W6}|EtYe:PC{n2)CYLp7k9X2^bTSU,&1A51!>f}]=i*~}!1=2TK/t?0q6qDH&LK8}R{KjW)S4?4+7YAvv:F
// YwU8k]_FsU|+PbS1FNexO;$q&3!i@Ff)T~WWj.0V,RX h$BR;J04~t#ciqxrrA)P>O~J59$L|vRya`G?$bTU4Im{1i","FT
// -ijub`jp&>eL#D8Nn}<{$CxFqOjNsyh|^coCkOLT7:u!p[b10:I{=|LYo&-#9Rkx/bsE[ZEJ~6S?$iE!eeJ%2Tku;lS3~|k-WZY_fN-E<XuV`z-VwHP@T+`5@peOec&S<0?[Cq:#f<>n15W_+(`V2(f9}px0jurmhZs>0&~AU3`^9musA}ufg_YM.!g*lDoqF>","oY]v;7wu*<xtian@^QsKI!$+(kP51jJ+Z<&teY2
// vlb&nL<Aw?ma MbM%fx{=aIjzO:[!t!pKdc-~9JBeS*?};ur.pLR/=KM(42cS h@EHGp1}`h@Jk8=?(^$YWN>Y#fev","Ii
// au6Q973UW<*gzq%-Rb[p)R7ekg;A9rLr0xJm~(AR>%4YG8~,p9jMzp/ Ui:.0VSYfxltb%3]SZx]^1lMQ
// XtbWH)0l#l@J*70.i+%v>BWP0-u6zwEO?YAM%w<Af$[2Yq{,g{UWIa9Ay}b#X#;RUTHOh!e$9K.%T3BPT>~[*FDP>},b9
// jZ%vii#8*W&cj%","+4
// Y+`<-jTc&(B/QbU.,.q],eLmaiDCs^KcO!dcxE6Cz%*q<?445{7)lF*w+4s)N3auE##!/7b?cs9`(.qpn+We)jA+%Tm/x~e:
// NqUdd[]6~$j`{pZD@qB^OfI3<|s*U;~6T9:q>lop@PYT=.WB,U*d5>]*ewS%WB,/gl6.48f","$V/Ff7[,;4]8q:i4R5Q^TEe)i@BhZ#qq-iq~$Sy^*Zp+Y&-h:}hWxP@TCd%C!Vq*6IWVyaQ+OMjH=Nf%>V@e7U,/hP;mg5B~1r}EdykyR
// nL{8{w|T$6OI)`%;JHdcQ#Lf+aEDOz{(=Ql-.3dV=~*9+MR,B%qqGxN|<ZdJ,Nk)v_QoaAXxDGjasD#Qbu?RVk/&","Z65.?cd@k!K%%r?]wS?!IhW^4UAt&?G0Mtpc+obWEN3p;D:0(ao)Di{>`%,/d4rJD):I3xy","/:#[mbv+]eb#6oV93%cw+q}NoGqj)","Bm<s.X<j}2W*9=kMpiSO]f$C%GJ*[2G&m$PeYtEf
// zHv(j&","xn6f4oET!}.f5u(80*(uU*^smzNw!mvP[r1eqirO:lS !Z}!$8-6B
// 7#11<:zl","q~","cspUgYsd#~%kf:VPcfEudZJcv2
// %>6Rp<GH58pX8[?S5","|C*?s_YW~PGp96#q-;4?dkzy4IB&~%YN#kk5#,!KDW%u","8DcH<=E,R.+.QZB>:^xD4U
// 3Ubckk?bO_v-qD<Ij9H)}C*GmAt~(J$S-G#=z",")J(hy;}{#pEJO2WCT?%t[:pmd^I@Cyl3c:)]pT","6lPs-zQ`W`oxv5Lr_xYt&tFVU&J/[>Tf6zZeha$6U`z!%!zs9/t},S-MbxF^-~,EQ=d1<eCF-+)MyLMeH9yvZJ{h#i6z/:ITx@S:RRlreMmprA1vUMJY!S)p,]#etmEM<L!A_n1^s4","w!(l`^[N#2#lLO{C0C)(qVn4BS6UKc,[5:Iy@MO(I%bP7~v7Ik]mn^m4vbIW!26`=-w","Qn}w3A5l_ckq1=pWSNUyma_Dn;lt9&Bw$?4(a(dK|8*V.gn#?P:G>gc8E|&wYM}otb?DSC<L9/#HW<u+k>E8[91<@cJ
// $sQn,,v#X{`nKPL0@xL9VU[,{AU|lE_:R9;I0?+Q_LLnP`/hT7/4/Vjltg,(f/Wrl$p/a","%f8q9sIZb>xBtuWDIhp_N%28PdaoHI9q{1","!tVXgS(yEG~biN;809`{_6(2PBCY)xUj1+t._=-k#hQfwc8$Q;-dUhfkN_wslV);gZAF(}=t7!9KS4+&R{!SCp;-JPY6aH2iS}t^uk*VVjg~{i!9;[!ATPtt!CN~28D<cfAAczB=:=2;eW:qZHU-nB<2616f-u?:N;v`o",">(EuvA3%94qJ;-h`e47W|X<K","I
// KOIC]kr`B!X0{9tHk.#MF0mdR~.[s1.5B<@vGr!@p7L6~dTP,L3n.=Z(2vnH,d[W+S*c)","sA<L20jG):muYSzT
// us-zi.F4p/8sd Fci^x^t,<k[#6ZR0/r-,k1;{nD0bAy>s7HVfIs/Kt):Qn?&VC@DE{}F-}5y)YOv<W`Bw
// IZtM:*henr@)z/3$4;|X/$}fE+1$98k1RI)L)1>4qy@n*Zlv8zi`K","f(3Emf^Q.SScuzg@dtJO?MM5,}xT^;i1z`0Z^L4e=<k)SCSP<&SNj|QhH<=k16)qS@$S0JZF$5<|JuPYboe","`X@pnZ8VwA6V&a&wBrf=aYD;c=rIR9wq/PeN3c#3$Z!xpek`W|wMT*tP?d0","bu*@N_`!AiTo)yH$C,e|4rGQpc5]Fj[iiTNa;t{v~fPa$*v8S24ejJ^,Q_1
// xk5i^BdF","fqj3=8R_5@3fQ;5N{ZgTHmX}5LJn#d7< z^xDMv4 97KlTX#~csp9xt~1t_m
// 3D[0nT(i}lx4>[FI4DRU,^|h/)P2ST3sx;$,L3<QnV=Vq>oTSI~VZ#45U
// =,3z3=s0$vEC3brHI=|",".vY2w,F&wPW/ty~N}h}22&!c*i=O=bqBuURz/hz7d?-{uutZ=5[il&,?}w46re4@cKFrgpwaCnp_b
// 9ktj
// a&(lg&f/pz},Y4RA},ghIf]adpYC</MRlN8#hAx-<=@e;uw;~H3|(^)rQ>S:H&9z7","9_Ef@st3i[hRV7AI`S^SCdSM4P-7g9&ab2h&8)z}8H|kR1@dNHy8+gg:Vuh|}v
// FT(iaB[TpVrz5iK?}B<;5v^+/{r(8WK)X@aoPFz)#NM,WNnki"]
