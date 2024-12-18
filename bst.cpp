#include <iostream>
#include <queue>
#include "bst.hpp"


BST::BST() {}

void BST::inorder(NodePtr root)const {  //LNR

    if (!root) {
        return;
    }//check if the tree itself is empty or we've reached a leaf node

    inorder(root->getLeft());//traverse through the ledt subtree

    cout << root->getAge();//print the age of the node we're at after getting back to it

    inorder(root->getRight());//traverse through the right subtree after traversing through left and printing the root


}

Node* BST::getRoot() {
    return root;
}

void BST::setRoot(Node* root) {
    this->root = root;
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

void BST::BFSPrivate(NodePtr root)const {
    if (!root)return;

    queue<Node*>q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->getAge() << " ";
        if (current->getLeft()) {
            q.push(current->getLeft());
        }
        if (current->getRight()) {
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

//Node* BST::nodeLoc( int age) {
//    Node* myPtr = root;
//    Node* parent = nullptr;
//    while (myPtr != nullptr) {
//        if (myPtr->getAge() < age) {
//            parent = myPtr;
//            myPtr = myPtr->getRight();
//        }
//        if (myPtr->getAge() > age) {
//            parent = myPtr;
//            myPtr = myPtr->getLeft();
//        }
//        if (myPtr->getAge() == age)
//            return myPtr;
//       
//
//    }
//
//    return nullptr;
//}


//insert

BST::NodePtr BST::createLeaf(Employee* item) {
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
 // Remove Node
void BST::remove(const Employee* item) {
    removePrivate(item, root);
}
void BST::removePrivate(const Employee* item, NodePtr parent) {
    int key = item->getAge();
    // Check for several cases (empty, root, no children, one child, two children)
    if (!empty()) {
        if (root->getAge() == key) {
            removeRootMatch(); // Helper function
        }
        else {
            // In left subtree
            if (key < parent->getAge() && parent->getLeft() != nullptr) {
                parent->getLeft()->getAge() == key
                    ? removeMatch(parent, parent->getLeft(), true) // Another helper function
                    : removePrivate(item, parent->getLeft()); // Recursive call
            }
            // In right subtree
            else if (key > parent->getAge() && parent->getRight() != nullptr) {
                parent->getRight()->getAge() == key
                    ? removeMatch(parent, parent->getRight(), false) // Another helper function
                    : removePrivate(item, parent->getRight()); // Recursive call
            }
            // Not in tree
            else {
                std::cout << "The node is not found\n";
            }
        }
    }
    else {
        std::cout << "The tree is empty\n";
    }
}
// Helper functions for removeNode function
void BST::removeRootMatch() {
    if (root != nullptr) {
        NodePtr delPtr = root;
        int rootData = root->getAge();
        int minInRightSubTree;
        // Case 0 - 0 Children
        if (root->getLeft() == nullptr && root->getRight() == nullptr) {
            root = nullptr;
            delete delPtr;
        }
        // Case 1 - 1 Child (left or right)
        else if (root->getLeft() == nullptr && root->getRight() != nullptr) {
            root = root->getRight();
            delPtr->setRight(nullptr);
            delete delPtr;
        }
        else if (root->getLeft() != nullptr && root->getRight() == nullptr) {
            root = root->getLeft();
            delPtr->setLeft(nullptr);
            delete delPtr;
        }
        // Case 2 - 2 Children
        else if (root->getLeft() != nullptr && root->getRight() != nullptr) {
            // Replace the root with the smallest value in the right subtree
            minInRightSubTree = findMinVal(root->getRight());
            Employee temp(minInRightSubTree, 0, 0); // Create a temporary Employee object
            removePrivate(&temp, root);
            root->setAge(minInRightSubTree);
        }
    }
    else {
        std::cout << "The tree is empty\n";
    }
}
void BST::removeMatch(NodePtr parent, NodePtr match, bool left) {
    if (!empty()) {
        NodePtr delPtr;
        int matchKey = match->getAge();
        int minInRightSubTree;
        // Case 0 - 0 Children
        if (match->getLeft() == nullptr && match->getRight() == nullptr) {
            delPtr = match;
            left == true ? parent->setLeft(nullptr) : parent->setRight(nullptr);
            delete delPtr;
        }
        // Case 1 - 1 Child (right child)
        else if (match->getLeft() == nullptr && match->getRight() != nullptr) {
            left == true ? parent->setLeft(match->getRight()) : parent->setRight(match->getRight());
            match->setRight(nullptr);
            delete match;
        }
        // Case 1 - 1 Child (left child)
        else if (match->getLeft() != nullptr && match->getRight() == nullptr) {
            left == true ? parent->setLeft(match->getLeft()) : parent->setRight(match->getLeft());
            match->setLeft(nullptr);
            delete match;
        }
        // Case 2 - 2 Children
        else if (match->getLeft() != nullptr && match->getRight() != nullptr) {
            minInRightSubTree = findMinVal(match->getRight());
            Employee temp(minInRightSubTree, 0, 0); // Create a temporary Employee object
            removePrivate(&temp, match);
            match->setAge(minInRightSubTree);
        }
    }
    else {
        std::cout << "The tree is empty\n";
    }
}
// Find minimum value
int BST::findMinVal(NodePtr ptr) {
    if (ptr != nullptr) {
        if (ptr->getLeft() == nullptr) // If you want to findMax, replace left with right
            return ptr->getAge();
        else
            return findMinVal(ptr->getLeft());
    }
    else {
        std::cout << "The tree is empty\n";
        return -1000; // In case of int
    }
}

int BST::findMaxVal(NodePtr ptr) {
    if (ptr != nullptr) {
        if (ptr->getRight() == nullptr) 
            return ptr->getAge();
        else
            return findMinVal(ptr->getRight());
    }
    else {
        std::cout << "The tree is empty\n";
        return -1000; // In case of int
    }
}

// Destructor
BST::~BST() {
    removeSubTree(root);
}
void BST::removeSubTree(NodePtr ptr) {
    // Post-order traversal
    if (ptr != nullptr) {
        if (ptr->getLeft() != nullptr)
            removeSubTree(ptr->getLeft());
        if (ptr->getRight() != nullptr)
            removeSubTree(ptr->getRight());
        delete ptr;
    }
}
