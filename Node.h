#ifndef NODE_H
#define NODE_H
#include "Employee.h"
#include <map>
#include <string>

class Node{
private:
  Employee* employee; //The node has a pointer to the object that hold the employee data
  Node* left;
  Node* right;
  //Memoized Values
  // int memoizedCount; //use this if we will implement the count query
  // double memoSumIncome;
  // double memoSumPerformance;
  // double memoAvgIncome;
  // double memoAvgPerformance;
  // double memoMaxIncome;
  // double memoMaxPerformance;
  // double memoMinIncome;
  // double memoMinPerformance;
  map<string, double> memo;

public:
  //constructor
  Node(Employee* emp);
  //setters
  void setLeft(Node* left);
  void setRight(Node* right);

  //getters
  //get the values of employee
  int getAge() const;
  double getIncome() const;
  double getPerformance() const;

  //get left & right of the node
  Node* getLeft() const;
  Node* getRight() const;

  // //get memoized values
  // double getMemoSumIncome();
  // double getMemoSumPerformance();
  // double getMemoMaxIncome();
  // double getMemoMaxPerformance();
  // double getMemoMinIncome();
  // double getMemoMinPerformance();
  // double getMemoAvgIncome();
  // double getMemoAvgPerformance();



  // //Memoization
  // void updateMemoizedVals(Node* root,  Node* curr); //pass the root

  void updateMemoizedVals(); // Updates all memoized values for this node
  double getMemoValue(const string& key); // Retrieves a memoized value by key


  //destructor
  ~Node();


};


#endif 
