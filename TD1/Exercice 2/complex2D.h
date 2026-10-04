#include <iostream>
using namespace std;

class Complex2D{
    private:
        double r,im;
    public:
    Complex2D();
    Complex2D(double r, double im);
    Complex2D(double val);
    Complex2D(const Complex2D &c);    

    void setReel(double r);
    void setIm(double im);
    double getReel();
    double getIm();

    Complex2D operator+(Complex2D c);
    Complex2D operator-(Complex2D c);
    Complex2D operator*(Complex2D c);
    Complex2D operator/(Complex2D c);
    bool operator<(Complex2D c);
    bool operator>(Complex2D c);
};