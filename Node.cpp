//
// Created by Nada Serour on 12/21/2024.
//

#include "Node.h"
#include "Employee.h"
#include <algorithm>
#include <iostream>
using namespace std;

// Constructor
Node::Node(double age, double income, double performance)
    : employee(age, income, performance), // Initialize the Employee object directly
      left(nullptr),
      right(nullptr),
      memoizedCount(1),
      memoSumIncome(income),
      memoSumPerformance(performance),
      memoAvgIncome(income),
      memoAvgPerformance(performance),
      memoMaxIncome(income),
      memoMaxPerformance(performance),
      memoMinIncome(income),
      memoMinPerformance(performance) {

    // Validation for age
    if (age < 18) {
        throw std::invalid_argument("Error: Age must be 18 or older.");
    }

    // Validation for income
    if (income < 0) {
        throw std::invalid_argument("Error: Income must be non-negative.");
    }

    // Validation for performance
    if (performance < 0) {
        throw std::invalid_argument("Error: Performance must be non-negative.");
    }

    // No need to manually create an Employee object because it’s already an object in the Node.
}


// Setters
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

// Getters
double Node::getAge() const {
    return employee.getAge();
}

double Node::getIncome() const { return employee.getIncome(); }

double Node::getPerformance() const { return employee.getPerformance(); }

Node* Node::getLeft() const { return left; }

Node* Node::getRight() const { return right; }

Node* Node::getParent() const { return parent; }

Employee Node::getEmployee() const { return employee; }

// Setters
void Node::setAge(double age) { employee.setAge(age); }

void Node::setIncome(double income) { employee.setIncome(income); }

void Node::setPerformance(double performance) { employee.setPerformance(performance); }

// Getters for memoized values
double Node::getMemoSumIncome() const{ return memoSumIncome; }

double Node::getMemoSumPerformance() const{ return memoSumPerformance; }

double Node::getMemoMaxIncome() const{ return memoMaxIncome; }

double Node::getMemoMaxPerformance() const { return memoMaxPerformance; }

double Node::getMemoMinIncome() const{ return memoMinIncome; }

double Node::getMemoMinPerformance() const{ return memoMinPerformance; }

double Node::getMemoAvgIncome() const{ return memoAvgIncome; }

double Node::getMemoAvgPerformance() const{ return memoAvgPerformance; }

// Memoization update function -- update with every change to the tree (ex: insert)
void Node::updateMemoizedVals() {
    // They are re-initialized here because we need to update if we changed
    // the right or the left of the node
    memoSumIncome = employee.getIncome();
    memoSumPerformance = employee.getPerformance();
    memoMaxIncome = employee.getIncome();
    memoMaxPerformance = employee.getPerformance();
    memoMinIncome = employee.getIncome();
    memoMinPerformance = employee.getPerformance();
    memoizedCount = 1;

    // If the left child exists
    if (left) {
        memoSumIncome += left->getMemoSumIncome();
        memoSumPerformance += left->getMemoSumPerformance();
        memoMaxIncome = max(memoMaxIncome, left->getMemoMaxIncome());
        memoMaxPerformance = max(memoMaxPerformance, left->getMemoMaxPerformance());
        memoMinIncome = min(memoMinIncome, left->getMemoMinIncome());
        memoMinPerformance = min(memoMinPerformance, left->getMemoMinPerformance());
        memoizedCount += left->memoizedCount;
    }

    // If the right child exists
    if (right) {
        memoSumIncome += right->getMemoSumIncome();
        memoSumPerformance += right->getMemoSumPerformance();
        memoMaxIncome = max(memoMaxIncome, right->getMemoMaxIncome());
        memoMaxPerformance = max(memoMaxPerformance, right->getMemoMaxPerformance());
        memoMinIncome = min(memoMinIncome, right->getMemoMinIncome());
        memoMinPerformance = min(memoMinPerformance, right->getMemoMinPerformance());
        memoizedCount += right->memoizedCount;
    }

    // Use sum and count to calculate the average
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

// Destructor
Node::~Node() {
    delete left;
    delete right;
}
