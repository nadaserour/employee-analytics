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
        template <typename ElementType2>
        void search2(const ElementType2& item, bool& found, Node*& locptr, Node*& parent) const;
        void insert(const Node item); //salma
        void remove(const Node item); //nada
        void inorder(Node* root) const; //renad
        void postOrder(Node* root)const;//renad
        void preOrder(Node* root)const;//renad
        void graph(ostream& out) const; //sara
        void BFS(Node * root)const;

};

#endif
