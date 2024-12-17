#ifndef NODE_H
#define NODE_H
#include "Employee.hpp"
#include <map>
#include <string>

using namespace std;
enum updateOperation {
	ADD,MULTIPLY,SUBTRACT,SET
};

class Node{
private:
  Employee* employee; //The node has a pointer to the object that hold the employee data
  Node* left;
  Node* right;
  Node* parent;
  //Memoized Values
   int memoizedCount; //use this if we will implement the count query
   double memoSumIncome;
   double memoSumPerformance;
   double memoAvgIncome;
   double memoAvgPerformance;
   double memoMaxIncome;
   double memoMaxPerformance;
   double memoMinIncome;
   double memoMinPerformance;
   double lazyValue = 0.0;
   bool lazyFlag = false;
   updateOperation operation;


public:
  //constructor
  Node(Employee* emp);
  //setters
  void setLeft(Node* left);
  void setRight(Node* right);
  void setParent(Node* parent);
  void setAge(int age);
  void setIncome(double income);
  void setPerformance(double performance);
  void setLazyValue(double lazyValue);
  void setLazyFlag(bool lazyFlag);
  void setOperation(updateOperation operation);

  //getters
  //get the values of employee
  int getAge() const;
  double getIncome() const;
  double getPerformance() const;
  double getLazyValue()const;
  bool getLazyFlag()const;
  updateOperation getOperation()const;


  //get left & right of the node
  Node* getLeft() const;
  Node* getRight() const;
  Node* getParent() const;

  // //get memoized values
   double getMemoSumIncome();
   double getMemoSumPerformance();
   double getMemoMaxIncome();
   double getMemoMaxPerformance();
   double getMemoMinIncome();
   double getMemoMinPerformance();
   double getMemoAvgIncome();
   double getMemoAvgPerformance();
   void applyLazy();



  // //Memoization
  // void updateMemoizedVals(Node* root,  Node* curr); //pass the root

  void updateMemoizedVals(); // Updates all memoized values for this node
  void updateTreeMemoizedVals(); //for tree propgation

  //destructor
  ~Node();


};


#endif 
