#include <iostream>
#include <vector>
#include "SearchingAlgo.h"
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    LinearSearch lineaire;
    JumpSearch saut;
    BinarySearch dicho;
    int res;

    cout << " Lineaire " << endl;
    res = lineaire.search(v, 3);
    lineaire.displaySearchResults(cout, res, 3);
    res = lineaire.search(v, 7);
    lineaire.displaySearchResults(cout, res, 7);

    cout << " Saut " << endl;
    res = saut.search(v, 3);
    saut.displaySearchResults(cout, res, 3);
    res = saut.search(v, 7);
    saut.displaySearchResults(cout, res, 7);

    cout << "Dichotomie" << endl;
    res = dicho.search(v, 3);
    dicho.displaySearchResults(cout, res, 3);
    res = dicho.search(v, 7);
    dicho.displaySearchResults(cout, res, 7);

    return 0;
}