//
// Created by Nada Serour on 12/21/2024.
//

#ifndef NODE_H
#define NODE_H


class Node {
    private:
    class Employee {
    public:
        double age;
        double income;
        double performance;
        Employee();
        Employee(double age, double income, double performance);
    };

    Node* left;
    Node* right;
    Node* parent{};
    // Memoized Values
    int memoizedCount; // Use this if we will implement the count query
    double memoSumIncome;
    double memoSumPerformance;
    double memoAvgIncome;
    double memoAvgPerformance;
    double memoMaxIncome;
    double memoMaxPerformance;
    double memoMinIncome;
    double memoMinPerformance;
    Employee employee;
    public:

    Node(double age, double income, double performance);

    Node();

    void setLeft(Node* left);
    void setRight(Node* right);
    void setParent(Node* parent);
    Node* getLeft() const;
    Node* getRight() const;
    Node* getParent() const;
    Employee getEmployee() const;

    // Get memoized values
    double getMemoSumIncome() const;
    double getMemoSumPerformance() const;
    double getMemoMaxIncome() const;
    double getMemoMaxPerformance() const;
    double getMemoMinIncome() const;
    double getMemoMinPerformance() const;
    double getMemoAvgIncome() const;
    double getMemoAvgPerformance() const;

    // Memoization
    void updateMemoizedVals(); // Updates all memoized values for this node
    void updateTreeMemoizedVals(); // For tree propagation

    // Destructor
    ~Node();

};



#endif //NODE_H
