#ifndef BST_H
#define BST_H
#include <iostream>
#include "Node.hpp"
using namespace std; 


class BST{
    typedef Node* NodePtr;
    private:
        NodePtr root;
		//aux for insert
        NodePtr createLeaf(Employee* item);
        NodePtr insertPrivate(Employee* item, NodePtr ptr);
		//aux for remove 
        void removePrivate(const Employee* item, NodePtr parent);
        void removeRootMatch();
        void removeMatch(NodePtr parent, NodePtr match, bool left);
        int findMinVal(NodePtr ptr); //int is the type for age
		//aux for destructor 
        void removeSubTree(NodePtr ptr);
		//aux for search
        template <typename ElementType>
        bool searchPrivate(const ElementType& item, bool& found, NodePtr& locptr, NodePtr& parent) const;
		//aux for BFS
        void BFSPrivate(NodePtr root)const;

    public:
        BST();
        ~BST();
        bool empty() const; //nada.
        template <typename ElementType>
        bool search(const ElementType& item) const; //sara
        void insert(Employee* item); //salma
        void remove(const Employee* item); //nada
        void inorder(NodePtr root) const; //renad
        //void postOrder(NodePtr root)const;//renad
        //void preOrder(NodePtr root)const;//renad
        void graph(ostream& out) const; //sara
        void BFS()const;


};

#endif
