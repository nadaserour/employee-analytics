
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


void Node::updateMemoizedVals() {
    //start with current node vals
    memo["sumIncome"] = employee->getIncome();
    memo["sumPerformance"] = employee->getPerformance();
    memo["maxIncome"] = employee->getIncome();
    memo["minIncome"] = employee->getIncome();
    memo["maxPerformance"] = employee->getPerformance();
    memo["minPerformance"] = employee->getPerformance();

    //include left child to update memoized vals
    if (left) {
        memo["sumIncome"] += left->getMemoValue("sumIncome");
        memo["sumPerformance"] += left->getMemoValue("sumPerformance");
        memo["maxIncome"] = max(memo["maxIncome"], left->getMemoValue("maxIncome"));
        memo["minIncome"] = min(memo["minIncome"], left->getMemoValue("minIncome"));
        memo["maxPerformance"] = max(memo["maxPerformance"], left->getMemoValue("maxPerformance"));
        memo["minPerformance"] = min(memo["minPerformance"], left->getMemoValue("minPerformance"));
    }

    //include right child to update memoized vals
    if (right) {
        memo["sumIncome"] += right->getMemoValue("sumIncome");
        memo["sumPerformance"] += right->getMemoValue("sumPerformance");
        memo["maxIncome"] = max(memo["maxIncome"], right->getMemoValue("maxIncome"));
        memo["minIncome"] = min(memo["minIncome"], right->getMemoValue("minIncome"));
        memo["maxPerformance"] = max(memo["maxPerformance"], right->getMemoValue("maxPerformance"));
        memo["minPerformance"] = min(memo["minPerformance"], right->getMemoValue("minPerformance"));
    }

    //To compute average
    int count = 1;
    if (left) count += left->getMemoValue("nodeCount");
    if (right) count += right->getMemoValue("nodeCount");
    memo["nodeCount"] = count;

    memo["avgIncome"] = memo["sumIncome"] / count;
    memo["avgPerformance"] = memo["sumPerformance"] / count;
}

double Node::getMemoValue(const string& key) {
    return memo[key];
}