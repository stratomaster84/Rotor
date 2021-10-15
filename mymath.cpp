//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mymath.h"

//---------------------------------------------------------------------------
#include <math.h>

long double C_Real(Complex z)
{
	return z.real;
}

long double __cos(long double x)
{
        long double _tmp;
        if(x <0)
                x = -x;
        if(x >= _2PI)
                x -= floorl(x/_2PI)*_2PI;

        if(x > _PI)
                x = _2PI - x;
        if(x > _PI_2)
                return -cosl(_PI - x);
        else
                return cosl(x);

}
long double __sin(long double x){
        return sinl(x);
}


long double C_Imaginary(Complex z)
{
	return z.imaginary;
}
long double C_Abs(Complex z)
{
	return sqrt(z.real*z.real + z.imaginary*z.imaginary);
}
long double C_Arg(Complex z)
{
	if(z.imaginary < 0)
		return _2PI + atan2(z.imaginary,z.real);
	else
		return atan2(z.imaginary,z.real);
}

Complex C_Conj(Complex z)
{
	return z.real - Im*z.imaginary;
}
Complex C_DefinePolar(long double wAbs,long double wArg)
{
	return wAbs*__cos(wArg) + Im*wAbs*__sin(wArg);
}	

Complex C_Exp(Complex z)
{
	return C_DefinePolar(exp(z.real),z.imaginary);
}
Complex C_Sin(Complex z)
{
	return __sin(z.real)*cosh(z.imaginary) + Im*__cos(z.real)*sinh(z.imaginary);
}
Complex C_Cos(Complex z)
{
	return __cos(z.real)*cosh(z.imaginary) - Im*__sin(z.real)*sinh(z.imaginary);
}
Complex C_Tg(Complex z)
{
	return C_Sin(z)/C_Cos(z);
}
Complex C_Sh(Complex z)
{
	return -Im*C_Sin(Im*z);
}
Complex C_Ch(Complex z)
{
	return C_Cos(Im*z);
}
Complex C_Th(Complex z)
{
	return C_Sh(z)/C_Ch(z);
}
Complex C_Ln(Complex z)
{
	return log(C_Abs(z)) + Im*C_Arg(z);
}
Complex C_Pow(Complex z1,Complex z2)
{
	long double x,y;
	x = log(C_Abs(z1));
	y = C_Arg(z1);
	return C_DefinePolar(exp(z2.real*x - y*z2.imaginary) , z2.imaginary*x + y*z2.real);
}
Complex C_Ash(Complex z)
{
	return C_Ln(z+C_Pow(z*z+1 , 0.5) );
}
Complex C_Ach(Complex z)
{
	return C_Ln(z+C_Pow(z*z-1 , 0.5) );
}
Complex C_Ath(Complex z)
{
	return C_Ln((1+z)/(1-z))/2;
}
Complex C_Asin(Complex z)
{
	return -Im*C_Ash(Im*z);
}
Complex C_Acos(Complex z)
{
	return Im*C_Ach(z);
}
Complex C_Atg(Complex z)
{
	return -Im*C_Ath(Im*z);
}


//---------------------------------------------------------------------------

#pragma package(smart_init)
