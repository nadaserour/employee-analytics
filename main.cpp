#include <iostream>
#include "cmake-build-debug/bst.h"
//#include "cmake-build-debug/Employee.h"
using namespace std;
int main() {
    // Create a BST instance
    BST tree;
    Node *node1 = new Node(45, 50000, 90);
    double age1= node1->getAge();
    double income1= node1->getIncome();
    double performance1= node1->getPerformance();
    // Create Employee instances
    //45, 15, 79, 90, 10, 55, 12, 20
    std::cout << "Inserting employees into the tree...\n";
    tree.insert(age1, income1, performance1);
   /* tree.insert(15, 50000, 90);
    tree.insert(79, 50000, 90);
    tree.insert(90, 50000, 90);
    tree.insert(10, 50000, 90);
    tree.insert(55, 50000, 90);
    tree.insert(12, 50000, 90);
    tree.insert(20, 50000, 90);

    // Test traversal (inorder)
    std::cout << "Inorder traversal of the tree:\n";
    tree.inorder();
    /*
    // Test search functionality
    std::cout << "\nSearching for Employee with age 25...\n";
    if (tree.search(*emp5)) {
        std::cout << "Employee with age 25 found.\n";
    }
    else {
        std::cout << "Employee with age 25 not found.\n";
    }

    // Test removal
    std::cout << "\nRemoving Employee with age 20...\n";
    tree.remove(emp2);
    std::cout << "Inorder traversal after removing Employee with age 20:\n";
    tree.inorder(tree.getRoot());
    // Test memoization updates
    std::cout << "\nTesting memoization updates...\n";
    node1.updateTreeMemoizedVals(); // Propagate memoization updates
    std::cout << "Memoized sum of incomes at root: " << node1.getMemoSumIncome() << "\n";
    std::cout << "Memoized average performance at root: " << node1.getMemoAvgPerformance() << "\n";
    // Test destructor (cleanup)
    std::cout << "\nDestroying the tree...\n";
    // Destructor will be called automatically when the program ends
    // Clean up dynamically allocated memory for employees

*/

    return 0;
}
