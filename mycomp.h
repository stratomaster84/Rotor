//---------------------------------------------------------------------------

#ifndef mycompH
#define mycompH
class Complex
{
public:
        long double real;
        long double imaginary;

        Complex();
        Complex(const Complex &z);
        Complex(long double x);
        Complex(long double x,long double y);

        void Add(Complex z);
        void Sub(Complex z);
        void Mul(Complex z);
        void Div(Complex z);

        Complex operator-();

        friend Complex operator+(Complex z1,Complex z2);
        friend Complex operator+(Complex z ,long double  x );
        friend Complex operator+(long double  x ,Complex z );

        friend Complex operator-(Complex z1,Complex z2);
        friend Complex operator-(Complex z ,long double  x );
        friend Complex operator-(long double  x ,Complex z );

        friend Complex operator*(Complex z1,Complex z2);
        friend Complex operator*(Complex z ,long double  x );
        friend Complex operator*(long double  x ,Complex z );

        friend Complex operator/(Complex z1,Complex z2);
        friend Complex operator/(Complex z ,long double  x );
        friend Complex operator/(long double  x ,Complex z );

        Complex operator+=(Complex z);
        Complex operator-=(Complex z);
        Complex operator*=(Complex z);
        Complex operator/=(Complex z);

        operator long double(){
                return real;
        }

        friend bool operator==(Complex z1,Complex z2);
        friend bool operator==(Complex z ,long double  x );
        friend bool operator==(long double  x ,Complex z );

        friend bool operator!=(Complex z1,Complex z2);
        friend bool operator!=(Complex z ,long double  x );
        friend bool operator!=(long double  x ,Complex z );

};

#define Im Complex(0,1)

//---------------------------------------------------------------------------
#endif
 