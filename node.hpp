#ifndef NODE
#define NODE

#include <iostream>
using namespace std;

class Node {

private: 
    //string name;
    float age;
    float income;
    //int bonus;
    double performance;
    //int experience;
    Node* left;
    Node* right;

public:
   Node(float age, float income, double performance);
   ~Node();
   void leftNode(Node* left);
   void rightNode(Node* right);
   Node* getLeft();
   Node* getRight();
   Node * getAge();

    //getters right and left and node 
    //memoization function
};



#endif