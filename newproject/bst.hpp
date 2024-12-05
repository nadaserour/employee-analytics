#ifndef BST_H
#define BST_H
#include <iostream>
#include "Node.hpp"
using namespace std; 

class BST{
    private:
        Node* root;
        Node* createLeaf(dataType item);
        void insertPrivate(const Employee* item, Node* ptr);




    public: 
        BST();
        bool empty() const; //nada.
        template <typename ElementType>
        bool search(const ElementType& item) const; //sara
        template <typename ElementType2>
        void search2(const ElementType2& item, bool& found, Node*& locptr, Node*& parent) const;
        void insert(const Employee* item); //salma
        void remove(const Node item); //nada
        void inorder(Node* root) const; //renad
        void postOrder(Node* root)const;//renad
        void preOrder(Node* root)const;//renad
        void graph(ostream& out) const; //sara
        void BFS(Node * root)const;


};

#endif
