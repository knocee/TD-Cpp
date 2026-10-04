#include <iostream>
using namespace std;

#include "header.h"

//  Exercice I:

/* 1.
int main(){
    std::cout << "Hello World!" << std::endl;
    return 0;
}*/

// 2.

void print2(string s){
    std::cout << s << std::endl;
}
//  3.

void myPrint3(string s){
    std::cout << s << std::endl;
}

// 4.


class my_class{
    private:
        string s;
    public:
        my_class(){};
        my_class(string s){
            this->s = s;
        }

        void print_my_element(){
            cout << s << endl;
        }
};

int main(){
    std::cout << "Hello World !" << std::endl;
    
    print2("Hello World !");
    
    myPrint3("Hello World !");
    
    my_class a;
    my_class b("Hello World !");
    a.print_my_element();
    b.print_my_element();
    return 0;
}