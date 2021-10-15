//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mycomp.h"
#include <math.h>

//---------------------------------------------------------------------------
Complex::Complex()
{
        real=imaginary=0;
}
Complex::Complex(const Complex &z)
{
        real = z.real;
        imaginary = z.imaginary;
}
Complex::Complex(long double x)
{
        real = x;
        imaginary = 0;
}
Complex::Complex(long double x,long double y)
{
        real = x;
        imaginary = y;
}
void Complex::Add(Complex z)
{
        real +=z.real;
        imaginary +=z.imaginary;
}
void Complex::Sub(Complex z)
{
        real -=z.real;
        imaginary -=z.imaginary;
}
void Complex::Mul(Complex z)
{
        long double tmp = real*z.real - imaginary*z.imaginary;
        imaginary = real*z.imaginary + imaginary*z.real;
        real = tmp;
}
void Complex::Div(Complex z)
{
        long double tmp = (real*z.real + imaginary*z.imaginary)/(z.real*z.real + z.imaginary*z.imaginary);
        imaginary = (-real*z.imaginary + imaginary*z.real)/(z.real*z.real + z.imaginary*z.imaginary);
        real = tmp;
}
Complex Complex::operator-()
{
        Complex tmp(*this);
        tmp.real = -real;
        tmp.imaginary = -imaginary;
        return tmp;
}
Complex Complex::operator+=(Complex z)
{
        real += z.real;
        imaginary +=z.imaginary;
        return *this;
}
Complex Complex::operator-=(Complex z)
{
        real -= z.real;
        imaginary -=z.imaginary;
        return *this;
}
Complex Complex::operator*=(Complex z)
{
        (*this).Mul(z);
        return *this;
}
Complex Complex::operator/=(Complex z)
{
        (*this).Div(z);
        return *this;
}
Complex operator+(Complex z1,Complex z2)
{
        Complex tmp(z1);
        tmp.Add(z2);
        return tmp;
}
Complex operator+(Complex z ,long double  x )
{
        Complex tmp(x);
        tmp.Add(z);
        return tmp;
}
Complex operator+(long double  x ,Complex z )
{
        Complex tmp(x);
        tmp.Add(z);
        return tmp;
}
Complex operator-(Complex z1,Complex z2)
{
        Complex tmp(z1);
        tmp.Sub(z2);
        return tmp;
}
Complex operator-(Complex z ,long double  x )
{
        Complex tmp(-x);
        tmp.Add(z);
        return tmp;
}
Complex operator-(long double  x ,Complex z )
{
        Complex tmp(x);
        tmp.Sub(z);
        return tmp;
}
Complex operator*(Complex z1,Complex z2)
{
        Complex tmp(z1);
        tmp.Mul(z2);
        return tmp;
}
Complex operator*(Complex z ,long double  x )
{
        Complex tmp(x);
        tmp.Mul(z);
        return tmp;
}
Complex operator*(long double  x ,Complex z )
{
        Complex tmp(x);
        tmp.Mul(z);
        return tmp;
}
Complex operator/(Complex z1,Complex z2)
{
        Complex tmp(z1);
        tmp.Div(z2);
        return tmp;
}
Complex operator/(Complex z ,long double  x )
{
        Complex tmp(1/x);
        tmp.Mul(z);
        return tmp;
}
Complex operator/(long double  x ,Complex z )
{
        Complex tmp(x);
        tmp.Div(z);
        return tmp;
}
bool operator==(Complex z1,Complex z2)
{
        if(z1.real == z2.real && z1.imaginary == z2.imaginary)
                return true;
        else
                return false;
}
bool operator==(Complex z ,long double  x )
{
        if(z.real == x)
                return true;
        else
                return false;
}
bool operator==(long double  x ,Complex z )
{
        if(z.real == x)
                return true;
        else
                return false;
}
bool operator!=(Complex z1,Complex z2)
{
        if(z1.real == z2.real && z1.imaginary == z2.imaginary)
                return false;
        else
                return true;
}
bool operator!=(Complex z ,long double  x )
{
        if(z.real != x)
                return true;
        else
                return false;
}
bool operator!=(long double  x ,Complex z )
{
        if(z.real != x)
                return true;
        else
                return false;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
 