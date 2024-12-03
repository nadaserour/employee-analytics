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
        void inorder(Node* root) const; //renad
        void postOrder(Node* root)const;//renad
        void preOrder(Node* root)const;//renad
        void graph(ostream& out) const; //sara
        void BFS(Node * root)const;

};

#endif
