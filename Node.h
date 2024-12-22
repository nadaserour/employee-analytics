//
// Created by Nada Serour on 12/21/2024.
//

#ifndef NODE_H
#define NODE_H
#include "Employee.h"
#include <string>

using namespace std;

class Node {
private:
    Employee employee; // The node has a pointer to the object that holds the employee data
    Node* left;
    Node* right;
    Node* parent;
    // Memoized Values
    int memoizedCount; // Use this if we will implement the count query
    double memoSumIncome;
    double memoSumPerformance;
    double memoAvgIncome;
    double memoAvgPerformance;
    double memoMaxIncome;
    double memoMaxPerformance;
    double memoMinIncome;
    double memoMinPerformance;

public:
    // Constructor
    Node(double age, double income, double performance);

    // Setters
    void setLeft(Node* left);
    void setRight(Node* right);
    void setParent(Node* parent);
    void setAge(double age);
    void setIncome(double income);
    void setPerformance(double performance);

    // Getters
    // Get the values of employee
    double getAge() const;
    double getIncome() const;
    double getPerformance() const;

    // Get pointers
    Node* getLeft() const;
    Node* getRight() const;
    Node* getParent() const;
    Employee getEmployee() const;

    // Get memoized values
    double getMemoSumIncome() const;
    double getMemoSumPerformance() const;
    double getMemoMaxIncome() const;
    double getMemoMaxPerformance() const;
    double getMemoMinIncome() const;
    double getMemoMinPerformance() const;
    double getMemoAvgIncome() const;
    double getMemoAvgPerformance() const;

    // Memoization
    void updateMemoizedVals(); // Updates all memoized values for this node
    void updateTreeMemoizedVals(); // For tree propagation

    // Destructor
    ~Node();
};

#endif