#include <iostream>
#include "complex2D.h"
using namespace std;

int main(){
    Complex2D z1;
    Complex2D a(2, 2);
    Complex2D b(2, 1);
    Complex2D z2(4);     
    Complex2D z3(a);

    Complex2D s = a + b;
    cout << "a + b = " << s.getReel() << " + " << s.getIm() << "i" << endl;

    Complex2D m = a - b;
    cout << "a - b = " << m.getReel() << " + " << m.getIm() << "i" << endl;

    Complex2D p = a * b;
    cout << "a * b = " << p.getReel() << " + " << p.getIm() << "i" << endl;

    Complex2D q = a / b;
    cout << "a / b = " << q.getReel() << " + " << q.getIm() << "i" << endl;

    if (a > b) {
        cout << "a > b" << endl;
    } else if (a < b) {
        cout << "a < b" << endl;
    } else {
        cout << "a et b ont la meme taille" << endl;}
    return 0;
}