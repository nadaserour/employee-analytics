#include "Node.hpp"
#include "Employee.hpp"
#include <algorithm>  
#include <numeric>    // For std::accumulate

using namespace std;

//constructor
// Node::Node(Employee* emp)
//     : employee(emp), left(nullptr), right(nullptr),
//       memoizedCount(1), memoSumIncome(emp->getIncome()), memoSumPerformance(emp->getPerformance()),
//       memoAvgIncome(emp->getIncome()), memoAvgPerformance(emp->getPerformance()),
//       memoMaxIncome(emp->getIncome()), memoMaxPerformance(emp->getPerformance()),
//       memoMinIncome(emp->getIncome()), memoMinPerformance(emp->getPerformance()) {}
Node::Node(Employee* emp)
    : employee(emp), left(nullptr), right(nullptr) {
    // Initialize memo with the current node's data
    memo["sumIncome"] = emp->getIncome();
    memo["maxIncome"] = emp->getIncome();
    memo["minIncome"] = emp->getIncome();
    memo["sumPerformance"] = emp->getPerformance();
    memo["maxPerformance"] = emp->getPerformance();
    memo["minPerformance"] = emp->getPerformance();
}

//setters
void Node::setLeft(Node* leftNode) {
    left = leftNode;
    updateMemoizedVals(); 
}

void Node::setRight(Node* rightNode) {
    right = rightNode;
    updateMemoizedVals();  
}

//getters
int Node::getAge() const { return employee->getAge(); }

double Node::getIncome() const { return employee->getIncome(); }

double Node::getPerformance() const { return employee->getPerformance(); }

Node* Node::getLeft() const { return left; }

Node* Node::getRight() const { return right; }

// getters for memoized values
// double Node::getMemoSumIncome() { return memoSumIncome; }

// double Node::getMemoSumPerformance() { return memoSumPerformance; }

// double Node::getMemoMaxIncome() { return memoMaxIncome; }

// double Node::getMemoMaxPerformance() { return memoMaxPerformance; }

// double Node::getMemoMinIncome() { return memoMinIncome; }

// double Node::getMemoMinPerformance() { return memoMinPerformance; }

// double Node::getMemoAvgIncome() { return memoAvgIncome; }

// double Node::getMemoAvgPerformance() { return memoAvgPerformance; }

// // memoization update function -- update with every change to the tree (ex: insert)
// void Node::updateMemoizedVals(Node* root, Node* curr) {
        //initial soln
// They are re-initialized here because we need to update if we changed 
//the right or the left of the node
// memoSumIncome = employee->getIncome();
// memoSumPerformance = employee->getPerformance();
// memoMaxIncome = employee->getIncome();
// memoMaxPerformance = employee->getPerformance();
// memoMinIncome = employee->getIncome();
// memoMinPerformance = employee->getPerformance();
// memoizedCount = 1;

// // if the left child exists
// if (left) {
//     memoSumIncome += left->getMemoSumIncome();
//     memoSumPerformance += left->getMemoSumPerformance();
//     memoMaxIncome = max(memoMaxIncome, left->getMemoMaxIncome());
//     memoMaxPerformance = max(memoMaxPerformance, left->getMemoMaxPerformance());
//     memoMinIncome = min(memoMinIncome, left->getMemoMinIncome());
//     memoMinPerformance = min(memoMinPerformance, left->getMemoMinPerformance());
//     memoizedCount += left->memoizedCount;
// }

// // if the right child exists
// if (right) {
//     memoSumIncome += right->getMemoSumIncome();
//     memoSumPerformance += right->getMemoSumPerformance();
//     memoMaxIncome = max(memoMaxIncome, right->getMemoMaxIncome());
//     memoMaxPerformance = max(memoMaxPerformance, right->getMemoMaxPerformance());
//     memoMinIncome = min(memoMinIncome, right->getMemoMinIncome());
//     memoMinPerformance = min(memoMinPerformance, right->getMemoMinPerformance());
//     memoizedCount += right->memoizedCount;
// }

// // use sum and count to calculate the average
// if (memoizedCount > 0) {
//     memoAvgIncome = memoSumIncome / memoizedCount;
//     memoAvgPerformance = memoSumPerformance / memoizedCount;
// }


//     //Brute Force - Recurrsive solution
//     //in order traversel , update 

//     if(root == curr){
//     memoSumIncome = employee->getIncome();
//     memoSumPerformance = employee->getPerformance();
//     memoMaxIncome = employee->getIncome();
//     memoMaxPerformance = employee->getPerformance();
//     memoMinIncome = employee->getIncome();
//     memoMinPerformance = employee->getPerformance();
//     }
//     else if(right){

//     }


//     //update the brute force code using memoization
  
    
// }

void Node::updateMemoizedVals() {
    //start with current node vals
    memo["sumIncome"] = employee->getIncome();
    memo["sumPerformance"] = employee->getPerformance();
    memo["maxIncome"] = employee->getIncome();
    memo["minIncome"] = employee->getIncome();
    memo["maxPerformance"] = employee->getPerformance();
    memo["minPerformance"] = employee->getPerformance();

    //include left child to update memoized vals
    if (left) {
        memo["sumIncome"] += left->getMemoValue("sumIncome");
        memo["sumPerformance"] += left->getMemoValue("sumPerformance");
        memo["maxIncome"] = max(memo["maxIncome"], left->getMemoValue("maxIncome"));
        memo["minIncome"] = min(memo["minIncome"], left->getMemoValue("minIncome"));
        memo["maxPerformance"] = max(memo["maxPerformance"], left->getMemoValue("maxPerformance"));
        memo["minPerformance"] = min(memo["minPerformance"], left->getMemoValue("minPerformance"));
    }

    //include right child to update memoized vals
    if (right) {
        memo["sumIncome"] += right->getMemoValue("sumIncome");
        memo["sumPerformance"] += right->getMemoValue("sumPerformance");
        memo["maxIncome"] = max(memo["maxIncome"], right->getMemoValue("maxIncome"));
        memo["minIncome"] = min(memo["minIncome"], right->getMemoValue("minIncome"));
        memo["maxPerformance"] = max(memo["maxPerformance"], right->getMemoValue("maxPerformance"));
        memo["minPerformance"] = min(memo["minPerformance"], right->getMemoValue("minPerformance"));
    }

    //To compute average
    int count = 1;
    if (left) count += left->getMemoValue("nodeCount");
    if (right) count += right->getMemoValue("nodeCount");
    memo["nodeCount"] = count;

    memo["avgIncome"] = memo["sumIncome"] / count;
    memo["avgPerformance"] = memo["sumPerformance"] / count;
}

double Node::getMemoValue(const string& key) {
    return memo[key];
}


//destructor
Node::~Node() { 
  delete employee;
  delete left;
  delete right; 
  }
