#include <iostream>
#include <queue>
#include "bst.hpp"


void BST:: inorder(NodePtr root)const{  //LNR

    if(!root){
        return;
    }//check if the tree itself is empty or we've reached a leaf node

    inorder(root->getLeft());//traverse through the ledt subtree

    cout<<root->getAge();//print the age of the node we're at after getting back to it

    inorder(root->getRight());//traverse through the right subtree after traversing through left and printing the root


}

/*

void BST::postOrder(NodePtr root)const{ //LRN
    
    if(!root)return;
    postOrder(root->getLeft());
    postOrder(root->getRight());
    cout<<root->getAge();

}

void BST::preOrder(NodePtr root)const{ //NLR
    
    if(!root)return;
    cout<<root->getAge();
    preOrder(root->getLeft());
    preOrder(root->getRight());

}
*/

void BST::BFS()const
{
    BFSPrivate(root);
}

void BST::BFSPrivate(NodePtr root)const{
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
	return root == nullptr;
}


//search
template <typename ElementType>
bool BST::search(const ElementType& item) const
{
    searchPrivate(item, false, root, nullptr);
}


//check for implementation
template <typename ElementType>
bool BST::searchPrivate(const ElementType& item, bool& found, Node*& locptr, Node*& parent) const {
	while (!found && locptr != nullptr) {
		if (item < locptr->getAge()) {
			parent = locptr;
			locptr = locptr->getLeft();
		}
		else if (locptr->getAge() < item) {
			parent = locptr;
			locptr = locptr->getLeft();
		}
		else found = true;
	}
}



//insert

BST::NodePtr BST::createLeaf(Employee* item){
  NodePtr leaf = new Node(item);
  return leaf;
}

void BST::insert(Employee* item) {
    root = insertPrivate(item, root); // Start insertion from the root
}


BST::NodePtr BST::insertPrivate(Employee* item, NodePtr ptr) {
    if (ptr == nullptr) {
        // Create a new leaf node if the current position is empty
        return createLeaf(item);
    }
    // Insert into the left subtree if the item's age is less than the current node's age
    if (item->getAge() < ptr->getAge()) {
        ptr->setLeft(insertPrivate(item, ptr->getLeft()));
    }
    // Insert into the right subtree if the item's age is greater than the current node's age
    else if (item->getAge() > ptr->getAge()) {
        ptr->setRight(insertPrivate(item, ptr->getLeft()));
    }
    // Handle duplicate data
    else {
        std::cout << "This item already exists\n";
        return ptr;
    }
    // Update memoized values of the current node after insertion
    ptr->updateTreeMemoizedVals();
    return ptr;

}


//remove
//Remove Node
 void remove(const Employee* item);{
  privateRemoveNode(item, root);
}
void BST::privateRemoveNode(Employee* item, NodePtr parent){
    int key = item->getAge();
  //we have to check for several cases (empty, root, no children, one child, 2 children) cases
  if(!empty()){
    if(root->getAge() == key){
      removeRootMatch(); //helper function
    } else{
      //in left sub tree
      if(key < parent->getAge() && parent->left != nullptr){
        parent->left->getAge() == key ?
        removeMatch(parent, parent->left, true): //another helper function
        privateRemoveNode(key, parent->left); //recurrsive call
      } 
      //in right sub tree
      else if(key > parent->data && parent->right != nullptr){
        parent->right->getAge() == key ?
        removeMatch(parent, parent->right, false): //another helper function
        privateRemoveNode(key, parent->right); //recurrsive call
      } 
      //not in tree
      else{
        cout << "The node is not found\n";
      }

    }

  } else
    cout << "The tree is empty\n";

}

//helper functions for removeNode function
void BST::removeRootMatch(){

  if(root != nullptr){
    NodePtr delPtr = root;
    int rootData = root->getAge();
    int minInRightSubTree;

    //Case 0 - 0 Children
    if(root->left == nullptr && root->right == nullptr){
      root = nullptr;
      delete delPtr;
    }
    
    //Case 1 - 1 Child (left - right)
    else if(root->left == nullptr && root->right != nullptr){
      root = root->right;
      delPtr->right = nullptr; //delete delPtr->right;
      delete delPtr;
    } 

    else if(root->left != nullptr && root->right == nullptr){
      root = root->left;
      delPtr->left = nullptr; //delete delPtr->left;
      delete delPtr;
    }

    //Case 2 - 2 children
    else if(root->left != nullptr && root->right != nullptr){
      //replace the root with the smallest val in right sub tree
      minInRightSubTree = privateFindMinVal(root->right);
      privateRemoveNode(minInRightSubTree, root);
      root->setAge(minInRightSubTree);
    }

  } else{
    cout << "The tree is empty\n";  
  }

}
 
void BST::removeMatch(NodePtr parent, NodePtr match, bool left){
  if(!empty()){

    NodePtr delPtr;
    int matchKey = match->getAge();
    int minInRightSubTree;

    //Case 0 - 0 children
    if(match->left == nullptr && match->right == nullptr){
      delPtr = match;
      left == true ? parent->left = nullptr : parent->right = nullptr;
      delete delPtr;
    }

    //Case 1 - 1 child 
    //right child
    else  if(match->left == nullptr && match->right != nullptr){
      //if the match node is the left node, by pass the parent left to be the right of the match node 
      left == true ? parent->left = match->right : parent->right = match->right;
      match->right = nullptr;
      delete match;
    }
    //left child
    else if(match->left != nullptr && match->right == nullptr){
      //if the match node is the left node, by pass the parent left to be the right of the match node 
      left == true ? parent->left = match->left : parent->right = match->left;
      match->left = nullptr;
      delete match;
    }

    //Case 2 - 2 children
    else if(match->left != nullptr && match->right != nullptr){
      minInRightSubTree = privateFindMinVal(match->right);
      privateRemoveNode(minInRightSubTree, root);
      match->setAge(minInRightSubTree);
    }

  } 
  else cout << "The tree is empty\n";
}


//find min value
int BST::findMinVal(NodePtr ptr){
  if(ptr != nullptr){
    if(ptr->left == nullptr) //if you want to findMax, all you have to do is replace left with right!! 
      return ptr->getAge();
    else
      return privateFindMinVal(ptr->left);

  } else{ 
    cout <<"The tree is empty\n";
    return -1000; //in case of int
  }
}


//Destructor
BST::~BST(){
  removeSubTree(root);
}

void BST::removeSubTree(NodePtr ptr){
  //post order traversal
  if(ptr != nullptr){
    if(ptr->left != nullptr)
      removeSubTree(ptr->left);
    if(ptr->right != nullptr)
      removeSubTree(ptr->right);
          
    delete ptr;

  }
} 







