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

bool BST::empty() const {
	return root == 0;
}

void BST:: remove(const Node item) {
	bool found;
	Node* itemPtr;
    Node* parent;
	search2(item, found, itemPtr, parent);

	if (!found) {
		cout << "employee not found\n";
			return;
	}
	if (itemPtr->getLeft() != 0 && itemPtr->getRight() != 0) {
		Node* itemSucc = itemPtr->getRight();
		parent = itemPtr;
		while (itemSucc->getLeft() != 0) {
			parent = itemSucc;
			itemSucc = itemSucc->getLeft();
		}
		itemPtr->getAge() = itemSucc->getAge();
		itemPtr = itemSucc;
	}
	Node* sub = itemPtr->getLeft();
	if (sub == 0) sub = itemPtr->getRight();
	if (parent == 0) root = sub;
	else if (parent->getLeft() == itemPtr) parent->getLeft() = sub;
	else parent->getRight() = sub;
	delete itemPtr;
}

template <typename ElementType2>
void BST::search2(const ElementType2& item, bool& found, Node*& locptr, Node*& parent) const {
	locptr = root;
	parent = 0; 
	found = false;
	while (!found && locptr != 0) {
		if (item < locptr->data) {
			parent = locptr;
			locptr = locptr->left;
		}
		else if (locptr->data < item) {
			parent = locptr;
			locptr = locptr->right;
		}
		else found = true;
	}
}

