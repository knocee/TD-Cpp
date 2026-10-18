#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>
#include <vector>
using namespace std;

class SearchingAlgo {
protected:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

public:
    SearchingAlgo();

    virtual int search(vector<int> v,int i)=0;

    void displaySearchResults(ostream& os, int result, int target);
};

class LinearSearch : public SearchingAlgo {
public:
    virtual int search(vector<int> v, int target) override;
};

class JumpSearch : public SearchingAlgo {
public:
    virtual int search(vector<int> v, int target) override;
};

class BinarySearch : public SearchingAlgo{
public:
    virtual int search(vector<int> v, int target) override;
};
#endif