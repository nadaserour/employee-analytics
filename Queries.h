//
// Created by Nada Serour on 12/21/2024.
//

#ifndef QUERIES_H
#define QUERIES_H
#include <iostream>
#include "Node.h"
#include "BST.h"
using namespace std;



class Queries {
private:
    void sumAndCountInc(Node* root, int minAge, int maxAge, double& sum, int& count);
    void sumAndCountPerf(Node* root, int minAge, int maxAge, double& sum, int& count);

public:

    double Income(int minAge, int maxAge,BST bst, bool AvgOrSum);
    double MaxIncome(int minAge, int maxAge, BST bst);
    double MinIncome(int minAge, int maxAge, BST bst);
    double Perf(int minAge, int maxAge, BST bst, bool AvgOrSum);
    double MinPerf(int minAge, int maxAge, BST bst);
    double MaxPerf(int minAge, int maxAge, BST bst);


};



#endif //QUERIES_H
