
#ifndef NODE_H
#define NODE_H
#include "Employee.hpp"
#include <map>
#include <string>

using namespace std;

class Node {
private:
	Employee* employee; //The node has a pointer to the object that hold the employee data
	Node* left=nullptr;
	Node* right=nullptr;
	Node* parent=nullptr;
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

	//getters
	//get the values of employee
	int getAge() const;
	double getIncome() const;
	double getPerformance() const;

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



	// //Memoization
	// void updateMemoizedVals(Node* root,  Node* curr); //pass the root

	void updateMemoizedVals(); // Updates all memoized values for this node
	void updateTreeMemoizedVals(); //for tree propgation

	//destructor
	~Node();


};


#endif 

