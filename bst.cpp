#include <iostream>
#include <queue>
#include "bst.hpp"

void BST:: inorder(Node*root)const{  //LNR

    if(!root){
        return;
    }//check if the tree itself is empty or we've reached a leaf node

    inorder(root->getLeft());//traverse through the ledt subtree

    cout<<root->getAge();//print the age of the node we're at after getting back to it

    inorder(root->getRight());//traverse through the right subtree after traversing through left and printing the root


}

void BST::postOrder(Node* root)const{ //LRN
    
    if(!root)return;
    postOrder(root->getLeft());
    postOrder(root->getRight());
    cout<<root->getAge();




}

void BST::preOrder(Node*root)const{ //NLR
    
    if(!root)return;
    cout<<root->getAge();
    preOrder(root->getLeft());
    preOrder(root->getRight());

}

void BST::BFS(Node*root)const{
    if(!root)return;

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* current= q.front();
        q.pop();
        cout<<current->getAge()<<" ";
        if(current->getLeft()){
            q.push(current->getLeft());
        }
        if(current->getRight()){
            q.push(current->getRight());
        }

    
    }

}



