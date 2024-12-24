#ifndef QUERIES
#define QUERIES
#include <iostream>
#include "bst.hpp"
using namespace std;


class Queries
{

private:
	void sumAndCountInc(Node* root, int minAge, int maxAge, double& sum, int& count); 
	void sumAndCountPerf(Node* root, int minAge, int maxAge, double& sum, int& count);
    void  collectTopKNodes(Node* root, int minAge, int maxAge, int K, bool isIncomeQuery, PriorityQueue& pq);

public:

	double Income(int minAge, int maxAge,BST bst, bool AvgOrSum);
	double MaxIncome(int minAge, int maxAge, BST bst);
	double MinIncome(int minAge, int maxAge, BST bst);
	double Perf(int minAge, int maxAge, BST bst, bool AvgOrSum);
	double MinPerf(int minAge, int maxAge, BST bst);
	double MaxPerf(int minAge, int maxAge, BST bst);
    void TopKNodes(int minAge, int maxAge, int K, bool isIncomeQuery, BST bst);


};
#endif
