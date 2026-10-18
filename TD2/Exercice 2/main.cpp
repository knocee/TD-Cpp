#include <iostream>
#include "MatrixBase.h"
using namespace std;

int main(){
    try{
        MatrixNumerical<double> A(3, 3);
        A.addElement(0, 0, 2); A.addElement(0, 1, 1); A.addElement(0, 2, 1);
        A.addElement(1, 0, 1); A.addElement(1, 1, 3); A.addElement(1, 2, 2);
        A.addElement(2, 0, 1);

        MatrixNumerical<double> B(3, 3);
        B.addElement(0, 0, 1); B.addElement(0, 1, 2);
        B.addElement(1, 1, 1);
        B.addElement(2, 2, 2);

        cout << "A :" << endl;          A.Display();
        cout << "B :" << endl;          B.Display();
        cout << "det(A) = " << A.getDeterminant() << endl;
        cout << "A + B :" << endl; (A + B).Display();
        cout << "A - B :" << endl; (A - B).Display();
        cout << "A * B :" << endl; (A * B).Display();
        cout << "inverse de A :" << endl; A.getInverse().Display();
        cout << "A * inverse(A) :" << endl; (A * A.getInverse()).Display();
        cout << "(A * B) / B :" << endl; ((A * B) / B).Display();
        cout << "identite 3x3 :" << endl;  MatrixNumerical<double>::getIdentity(3).Display();

        MatrixNumerical<double> C(2, 2);
        cout << "inverse de C :" << endl;
        C.getInverse().Display();
    }
    catch (const char* msg){
        cout << "Erreur : " << msg << endl;
    }
    return 0;
}