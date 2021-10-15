//---------------------------------------------------------------------------

#ifndef mymathH
#define mymathH

#include "mycomp.h"

#define _2PI 6.283185307179586476926
#define _PI  3.141592653589793238462
#define _PI_2 1.570796326794896619231

//---------------------------------------------------------------------------
long double __cos(long double x);
long double __sin(long double x);
long double C_Real(Complex z);
long double C_Imaginary(Complex z);
long double C_Abs(Complex z);
long double C_Arg(Complex z);
Complex C_Conj(Complex z);
Complex C_DefinePolar(long double wAbs,long double wArg);
Complex C_Exp(Complex z);
Complex C_Sin(Complex z);
Complex C_Cos(Complex z);
Complex C_Tg(Complex z);
Complex C_Sh(Complex z) ;
Complex C_Ch(Complex z);
Complex C_Th(Complex z);
Complex C_Ln(Complex z) ;
Complex C_Pow(Complex z1,Complex z2) ;
Complex C_Ash(Complex z) ;
Complex C_Ach(Complex z);
Complex C_Ath(Complex z);
Complex C_Asin(Complex z);
Complex C_Acos(Complex z);
Complex C_Atg(Complex z) ;
//---------------------------------------------------------------------------
#endif
 