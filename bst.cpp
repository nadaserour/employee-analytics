//
// Created by Nada Serour on 12/21/2024.
//

#include <iostream>
#include "bst.h"

BST::BST() {}

void BST::inorder() const {
    inorderPrivate(root);
}

void BST::inorderPrivate(NodePtr ptr) const {  // LNR
    if (empty()) {
        return;
    } // Check if the tree itself is empty or we've reached a leaf node

    inorderPrivate(ptr->getLeft()); // Traverse through the left subtree
    cout << ptr->getAge() << " "; // Print the age of the node we're at after getting back to it
    inorderPrivate(ptr->getRight()); // Traverse through the right subtree after traversing through left and printing the root
}

Node* BST::getRoot() {
    return root;
}

void BST::setRoot(Node* root) {
    this->root = root;
}

// void BST::BFS() const {
//     BFSPrivate(root);
// }

// void BST::BFSPrivate(NodePtr root) const {
//     if (!root) return;
//
//     queue<Node*> q;
//     q.push(root);
//     while (!q.empty()) {
//         Node* current = q.front();
//         q.pop();
//         cout << current->getAge() << " ";
//         if (current->getLeft()) {
//             q.push(current->getLeft());
//         }
//         if (current->getRight()) {
//             q.push(current->getRight());
//         }
//     }
// }

bool BST::empty() const {
    return root == nullptr;
}

// Search
bool BST::search(double age) const {
    return searchPrivate(age, root); // Pass root directly
}

bool BST::searchPrivate(double age, NodePtr locptr) const {
    while (locptr != nullptr) {
        if (age < locptr->getAge()) {
            locptr = locptr->getLeft(); // Traverse left subtree
        } else if (locptr->getAge() < age) {
            locptr = locptr->getRight(); // Traverse right subtree
        } else {
            return true; // Found the item
        }
    }
    return false; // Item not found
}

// Insert
BST::NodePtr BST::createLeaf(double age, double income, double performance) {
    NodePtr leaf = new Node (age, income, performance);
    return leaf;
}

void BST::insert(double age, double income, double performance) {
    root = insertPrivate(age, income, performance, root); // Start insertion from the root
}

BST::NodePtr BST::insertPrivate(double age, double income, double performance, NodePtr ptr) {
    if (ptr == nullptr) {
        // Create a new leaf node if the current position is empty
        return createLeaf(age, income, performance);  // Directly create a Node with age, income, and performance
    }

    // Insert into the left subtree if the item's age is less than the current node's age
    if (age < ptr->getAge()) {
        ptr->setLeft(insertPrivate(age, income, performance, ptr->getLeft()));
    }
    // Insert into the right subtree if the item's age is greater than the current node's age
    else if (age > ptr->getAge()) {
        ptr->setRight(insertPrivate(age, income, performance, ptr->getRight()));
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

// Remove
void BST::remove(double age) {
    removePrivate(age, root);
}

void BST::removePrivate(double age, NodePtr parent) {
    // Check for the base case where the tree is empty
    if (!empty()) {
        if (root->getAge() == age) {
            removeRootMatch(); // Helper function for removing the root match
        } else {
            // In left subtree
            if (age < parent->getAge()) {
                if (parent->getLeft() != nullptr && parent->getLeft()->getAge() == age) {
                    removeMatch(parent, parent->getLeft(), true);
                } else {
                    removePrivate(age, parent->getLeft());
                }
            }
            // In right subtree
            else if (age > parent->getAge()) {
                if (parent->getRight() != nullptr && parent->getRight()->getAge() == age) {
                    removeMatch(parent, parent->getRight(), false);
                } else {
                    removePrivate(age, parent->getRight());
                }
            } else {
                std::cout << "The node is not found\n";
            }
        }
    } else {
        std::cout << "The tree is empty\n";
    }
}

// Helper functions for removeNode function
void BST::removeRootMatch() {
    if (root != nullptr) {
        NodePtr delPtr = root;
        int rootAge = root->getAge();
        double rootIncome = root->getIncome();
        double rootPerformance = root->getPerformance();
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
        } else if (root->getLeft() != nullptr && root->getRight() == nullptr) {
            root = root->getLeft();
            delPtr->setLeft(nullptr);
            delete delPtr;
        }
        // Case 2 - 2 Children
        else if (root->getLeft() != nullptr && root->getRight() != nullptr) {
            // Replace the root with the smallest value in the right subtree
            minInRightSubTree = findMinVal(root->getRight());
            Employee temp(minInRightSubTree, 0, 0); // Create a temporary Employee object
            removePrivate(temp.getAge(), root);
            root->setAge(minInRightSubTree);
        }
    } else {
        std::cout << "The tree is empty\n";
    }
}

void BST::removeMatch(NodePtr parent, NodePtr match, bool left) {
    if (!empty()) {
        NodePtr delPtr;
        int matchAge = match->getAge();
        double matchIncome = match->getIncome();
        double matchPerformance = match->getPerformance();
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
            removePrivate(temp.getAge(), match);
            match->setAge(minInRightSubTree);
        }
    } else {
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
    } else {
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
    } else {
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
        if (ptr->getLeft() != nullptr) {
            removeSubTree(ptr->getLeft());
        }
        if (ptr->getRight() != nullptr) {
            removeSubTree(ptr->getRight());
        }
        delete ptr;
    }

}
