#ifndef BST_H
#define BST_H
#include <iostream>
#include "node.hpp"
using namespace std; 

class BST{
    private:
        Node* root;


    public: 
        BST();
        bool empty() const; //nada
        template <typename ElementType>
        bool search(const ElementType& item) const; //sara
        void insert(const Node item); //salma
        void remove(const Node item); //nada
        void inorder(ostream& out) const; //renad
        void graph(ostream& out) const; //sara

};

#endif
