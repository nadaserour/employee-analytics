
//When calling updateMemoizatino

//Smaple scenario when we need to use update Memo is insert()
insertNode(node);  

node->updateMemoizedVals(); //update the curr node 

//propagate the changes to the parents in this sub tree
Node* parent = node->getParent(); //we need to implement the getParent helper method
while (parent) {
    parent->updateMemoizedVals();
    parent = parent->getParent(); 
}



//Queries example
double Node::queryMaxIncome(int minAge, int maxAge) {
    double result = (employee->getAge() >= minAge && employee->getAge() <= maxAge) ? employee->getIncome() : -1;
    
    //check if left child exit
    if (left) {
        if (left->getAge() >= minAge && left->getAge() <= maxAge) {
            result = max(result, left->getMemoValue("maxIncome"));
        }
        else {
            result = max(result, left->queryMaxIncome(minAge, maxAge)); // recurse to the left subtree
        }
    }

    //check if right child exist
    if (right) {
        if (right->getAge() >= minAge && right->getAge() <= maxAge) {
            result = max(result, right->getMemoValue("maxIncome"));
        }
        else {
            result = max(result, right->queryMaxIncome(minAge, maxAge)); // recurse to the right subtree
        }
    }
    
    return result;
}

//sum performance for max age
double Node::querySumPerformance(int maxAge) {
    double result = (employee->getAge() < maxAge) ? employee->getPerformance() : 0;
    
    //check if left child exists
    if (left) {
        if (left->getAge() < maxAge) {
            result += left->getMemoValue("sumPerformance");
        }
        else {
            result += left->querySumPerformance(maxAge); // recurse to the left subtree
        }
    }

    // Check if right child exists 
    if (right) {
        if (right->getAge() < maxAge) {
            result += right->getMemoValue("sumPerformance");
        }
        else {
            result += right->querySumPerformance(maxAge); // recurse to the right subtree
        }
    }
    
    return result;
}
