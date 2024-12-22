//
// Created by Nada Serour on 12/21/2024.
//

#pragma once

#ifndef BST_H
#define BST_H

#include <iostream>
#include "Node.h"
using namespace std;


class BST {
    typedef Node* NodePtr;
private:
    NodePtr root;
    NodePtr createLeaf(double age, double income, double performance);
    NodePtr insertPrivate(double age, double income, double performance, NodePtr ptr);
    //void removePrivate(double age, NodePtr parent);
  //  void removeRootMatch();
    //void removeMatch(NodePtr parent, NodePtr match, bool left);
    //int findMinVal(NodePtr ptr); //int is the type for age
    //int findMaxVal(NodePtr ptr);
    void removeSubTree(NodePtr ptr);
    bool searchPrivate(double age, NodePtr locptr) const;
    //aux for BFS
    //void BFSPrivate(NodePtr root)const;
    void inorderPrivate(NodePtr ptr)const;


public:
    BST();
    ~BST();

    void setRoot(Node* root);
    NodePtr getRoot();
    bool empty() const; //nada
    bool search(double age) const; //sara
    void insert(double age, double income, double performance); //salma
    //void remove(double age); // Updated remove method with the new parameters
    void inorder() const; //renad
    //void postOrder(NodePtr root)const;//renad
    //void preOrder(NodePtr root)const;//renad
    //void graph(ostream& out) const; //sara
    //void BFS()const;
    int findMinVal(NodePtr ptr); //int is the type for age
    int findMaxVal(NodePtr ptr);




};

#endif