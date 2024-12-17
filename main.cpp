#include <iostream>
#include "bst.hpp"
#include "Employee.hpp"
int main() {
    // Create a BST instance
    BST tree;
    // Create Employee instances
    Employee* emp1 = new Employee(30, 50000, 90);
    Employee* emp2 = new Employee(20, 40000, 85);
    Employee* emp3 = new Employee(40, 60000, 95);
    Employee* emp4 = new Employee(10, 30000, 80);
    Employee* emp5 = new Employee(25, 45000, 88);
    Employee* emp6 = new Employee(35, 55000, 92);
    Employee* emp7 = new Employee(50, 70000, 98);
    // Test insertion
    std::cout << "Inserting employees into the tree...\n";
    tree.insert(emp1);
    tree.insert(emp2);
    tree.insert(emp3);
    tree.insert(emp4);
    tree.insert(emp5);
    tree.insert(emp6);
    tree.insert(emp7);
    // Test traversal (inorder)
    std::cout << "Inorder traversal of the tree:\n";
    tree.inorder(tree.getRoot());
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
    emp1->updateTreeMemoizedVals(); // Propagate memoization updates
    std::cout << "Memoized sum of incomes at root: " << emp1->getMemoSumIncome() << "\n";
    std::cout << "Memoized average performance at root: " << emp1->getMemoAvgPerformance() << "\n";
    // Test destructor (cleanup)
    std::cout << "\nDestroying the tree...\n";
    // Destructor will be called automatically when the program ends
    // Clean up dynamically allocated memory for employees
    delete emp1;
    delete emp2;
    delete emp3;
    delete emp4;
    delete emp5;
    delete emp6;
    delete emp7;
    return 0;
}