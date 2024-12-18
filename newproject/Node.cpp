#include "Node.hpp"
#include "Employee.hpp"
#include <algorithm>  

using namespace std;

//constructor
 Node::Node(Employee* emp)
     : employee(emp), left(nullptr), right(nullptr),
       memoizedCount(1), memoSumIncome(emp->getIncome()), memoSumPerformance(emp->getPerformance()),
       memoAvgIncome(emp->getIncome()), memoAvgPerformance(emp->getPerformance()),
       memoMaxIncome(emp->getIncome()), memoMaxPerformance(emp->getPerformance()),
       memoMinIncome(emp->getIncome()), memoMinPerformance(emp->getPerformance()) {}



//setters
void Node::setLeft(Node* left) {
    this->left = left;
    if (left) {
        left->parent = this; // Set the parent pointer of the left child
    }
   left->updateTreeMemoizedVals(); // Propagate updates upwards
}

void Node::setRight(Node* right) {
    this->right = right;
    if (right) {
        right->parent = this; // Set the parent pointer of the right child
    }
    right->updateTreeMemoizedVals(); // Propagate updates upwards
}
void Node::setParent(Node* parent) {
    this->parent = parent;
}



//getters
int Node::getAge() const { return employee->getAge(); }

double Node::getIncome() const { return employee->getIncome(); }

double Node::getPerformance() const { return employee->getPerformance(); }

Node* Node::getLeft() const { return left; }

Node* Node::getRight() const { return right; }

Node* Node::getParent() const { return parent; }

//setters 

void Node::setAge(int age) { employee->setAge(age); }

void Node::setIncome(double income) { employee->setIncome(income); }

void Node::setPerformance(double performance) { employee->setPerformance(performance); }

// getters for memoized values
double Node::getMemoSumIncome() { return memoSumIncome; }

double Node::getMemoSumPerformance() { return memoSumPerformance; }

double Node::getMemoMaxIncome() { return memoMaxIncome; }

double Node::getMemoMaxPerformance() { return memoMaxPerformance; }

double Node::getMemoMinIncome() { return memoMinIncome; }

double Node::getMemoMinPerformance() { return memoMinPerformance; }

double Node::getMemoAvgIncome() { return memoAvgIncome; }

double Node::getMemoAvgPerformance() { return memoAvgPerformance; }

// // memoization update function -- update with every change to the tree (ex: insert)
 void Node::updateMemoizedVals() {
        //initial soln
// They are re-initialized here because we need to update if we changed 
//the right or the left of the node
memoSumIncome = employee->getIncome();
memoSumPerformance = employee->getPerformance();
memoMaxIncome = employee->getIncome();
memoMaxPerformance = employee->getPerformance();
memoMinIncome = employee->getIncome();
memoMinPerformance = employee->getPerformance();
memoizedCount = 1;

// // if the left child exists
if (left) {
     memoSumIncome += left->getMemoSumIncome();
     memoSumPerformance += left->getMemoSumPerformance();memoMaxIncome = max(memoMaxIncome, left->getMemoMaxIncome());
     memoMaxPerformance = max(memoMaxPerformance, left->getMemoMaxPerformance());
     memoMinIncome = min(memoMinIncome, left->getMemoMinIncome());memoMinPerformance = min(memoMinPerformance, left->getMemoMinPerformance());
     memoizedCount += left->memoizedCount;
	}

// // if the right child exists
if (right) {
     memoSumIncome += right->getMemoSumIncome();
     memoSumPerformance += right->getMemoSumPerformance();
     memoMaxIncome = max(memoMaxIncome, right->getMemoMaxIncome());
     memoMaxPerformance = max(memoMaxPerformance, right->getMemoMaxPerformance());
     memoMinIncome = min(memoMinIncome, right->getMemoMinIncome());
     memoMinPerformance = min(memoMinPerformance, right->getMemoMinPerformance());
     memoizedCount += right->memoizedCount;
	}

// // use sum and count to calculate the average
 if (memoizedCount > 0) {
     memoAvgIncome = memoSumIncome / memoizedCount;
     memoAvgPerformance = memoSumPerformance / memoizedCount;
	}

}



// Tree propagation
void Node::updateTreeMemoizedVals() {
    Node* current = this;
    while (current) {
        current->updateMemoizedVals(); // Update memoized values for the current node
        current = current->getParent(); // Move to the parent node
    }
}

void Node:: applyLazy() {
    if (lazyFlag) {
        switch (operation) {
        case ADD:
            employee->setPerformance(employee->getPerformance()+lazyValue;
            break;
        case MULTIPLY:
            employee->setPerformance(employee->getPerformance() * (1 + lazyValue));
            break;
        case SUBTRACT:
            employee->setPerformance(employee->getPerformance() - lazyValue);
            break;
        case SET:
            employee->setPerformance(lazyValue);
            break;
        }
    }
    lazyFlag = false;
    lazyValue = 0.0;
}

double Node::getLazyValue() {
    return lazyValue;
}

bool Node::getLazyFlag() {
    return lazyFlag;
}

void Node::setLazyFlag(bool lazyFlag) {
    this->lazyFlag = lazyFlag;
}

void Node::setLazyValue(double lazyValue) {
    this->lazyValue = lazyValue;
}

updateOperation Node::getOperation() {
    return operation;
}

void Node::setOperation(updateOperation operation) {
    this->operation = operation;
}

//destructor
Node::~Node() { 
  delete employee;
  delete left;
  delete right;
  }
