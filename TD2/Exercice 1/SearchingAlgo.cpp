#include "SearchingAlgo.h"
#include <cmath>

int SearchingAlgo::totalComparisons = 0;
int SearchingAlgo::totalSearch = 0;
double SearchingAlgo::averageComparisons = 0;

SearchingAlgo::SearchingAlgo():numberComparisons(0){}

void SearchingAlgo::displaySearchResults(ostream& os, int result, int target){
    totalComparisons = totalComparisons + numberComparisons;
    totalSearch = totalSearch + 1;
    averageComparisons = (double)totalComparisons / totalSearch;

    if (result == -1)
        os << target << " : non trouve";
    else
        os << target << " : indice " << result;

    os << " en " << numberComparisons << " comparaisons" << endl;
    os << " total : " << totalComparisons << " comparaisons pour "
       << totalSearch << " recherches, moyenne : " << averageComparisons << endl;
}

int LinearSearch::search(vector<int> v, int target){
    numberComparisons = 0;
    for (int i = 0; i < v.size(); i++){
        numberComparisons++;
        if (v[i] == target)
            return i;
    }
    return -1;
}

int JumpSearch::search(vector<int> v, int target){
    numberComparisons = 0;
    int pas = sqrt(v.size());
    int debut = 0;
    while (debut < v.size()){
        int fin = debut + pas - 1;
        if (fin >= v.size())
            fin = v.size() - 1;

        numberComparisons++;
        if (v[fin] >= target)
            break;
        debut = debut + pas;
    }

    for (int i = debut; i < debut + pas && i < v.size(); i++){
        numberComparisons++;
        if (v[i] == target)
            return i;
    }
    return -1;
}

int BinarySearch::search(vector<int> v, int target){
    numberComparisons = 0;
    int gauche = 0;
    int droite = v.size() - 1;
    while (gauche <= droite){
        int milieu = (gauche + droite) / 2;
        numberComparisons++;
        if (v[milieu] == target)
            return milieu;
        else if (v[milieu] < target)
            gauche = milieu + 1;
        else
            droite = milieu - 1;
    }
    return -1;
}