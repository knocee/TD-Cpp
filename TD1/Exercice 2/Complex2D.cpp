#include "complex2D.h"
#include <iostream>
using namespace std;

Complex2D::Complex2D(){
    r=0,im=0;
}
Complex2D::Complex2D(double r, double im){
    this->r=r,this->im=im;
}
Complex2D::Complex2D(double val){
    r=val,im=val;
}
Complex2D::Complex2D(const Complex2D &c){
    r=c.r;
    im=c.im;
}

double Complex2D::getReel(){
    return r;
}
double Complex2D::getIm(){
    return im;
}
void Complex2D::setReel(double r){
    this->r=r;
}
void Complex2D::setIm(double im){
    this->im=im;
}

Complex2D Complex2D::operator+(Complex2D c){
    Complex2D res;
    res.r = r + c.r;
    res.im = im + c.im;
    return res;
}

Complex2D Complex2D::operator-(Complex2D c){
    Complex2D res;
    res.r = r - c.r;
    res.im = im - c.im;
    return res;
}

Complex2D Complex2D::operator*(Complex2D c){
    Complex2D res;
    res.r = r * c.r - im * c.im;
    res.im = r * c.im + im * c.r;
    return res;
}

Complex2D Complex2D::operator/(Complex2D c){
    double d = c.r * c.r + c.im * c.im;
    Complex2D res;
    res.r = (r * c.r + im * c.im) / d;
    res.im = (im * c.r - r * c.im) / d;
    return res;
}

bool Complex2D::operator<(Complex2D c){
    return r*r + im*im < c.r*c.r + c.im*c.im;
}

bool Complex2D::operator>(Complex2D c){
    return r*r + im*im > c.r*c.r + c.im*c.im;
}