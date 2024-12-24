//
// Created by Nada Serour on 12/21/2024.
//

#include "Queries.h"
#include "Node.h"
#include "BST.h"
#include "PriorityQueue.hpp"
#include <iostream>
using namespace std;

void Queries:: sumAndCountInc(Node* root, int minAge, int maxAge, double& sum, int& count) {
	if (root == nullptr) return;

	if (root->getEmployee().age > minAge) sumAndCountInc(root->getLeft(), minAge, maxAge, sum, count);

	if (root->getEmployee().age >= minAge && root->getEmployee().age <= maxAge) {
		sum += root->getEmployee().income;
		count++;
	}
	if (root->getEmployee().age < maxAge) sumAndCountInc(root->getRight(), minAge, maxAge, sum, count);
}

void Queries::sumAndCountPerf(Node* root, int minAge, int maxAge, double& sum, int& count) {
	if (root == nullptr) return;

	if (root->getEmployee().age > minAge) sumAndCountPerf(root->getLeft(), minAge, maxAge, sum, count);

	if (root->getEmployee().age >= minAge && root->getEmployee().age <= maxAge) {
		sum += root->getEmployee().performance;
		count++;
	}
	if (root->getEmployee().age < maxAge) sumAndCountPerf(root->getRight(), minAge, maxAge, sum, count);
}


double Queries:: Income(int minAge, int maxAge, BST bst, bool AvgOrSum) {
	double sum = 0;
	int count = 0;

	sumAndCountInc(bst.getRoot(), minAge, maxAge, sum, count);

	return AvgOrSum ? sum : (count > 0 ? sum / count : 0.0);
}

double Queries::Perf(int minAge, int maxAge, BST bst, bool AvgOrSum) {
	double sum = 0;
	int count = 0;

	sumAndCountPerf(bst.getRoot(), minAge, maxAge, sum, count);

	return AvgOrSum ? sum : (count > 0 ? sum / count : 0.0);
}

double Queries::MaxIncome(int minAge, int maxAge, BST bst) {
	double maxInc = 0;
	Node* currentPtr = bst.getRoot();

	while (currentPtr != nullptr) {
		if (currentPtr->getEmployee().age < minAge)
			currentPtr = currentPtr->getRight();

		else if (currentPtr->getEmployee().age > maxAge)
			currentPtr = currentPtr->getLeft();
		else {
			maxInc = max(maxInc, currentPtr->getEmployee().income);
			if (currentPtr->getRight() != nullptr) {
				Node* temp = currentPtr->getRight();
				while (temp != nullptr) {
					if (minAge <= temp->getEmployee().age && temp->getEmployee().age <= maxAge) {
						maxInc = max(maxInc, temp->getEmployee().income);
						temp = temp->getLeft();
					}
					else if (temp->getEmployee().age < minAge)
						temp = temp->getRight();
					else temp = temp->getLeft();
				}
			}

			if (currentPtr->getLeft() != nullptr) {
				Node* temp = currentPtr->getLeft();
				while (temp != nullptr) {
					if (minAge <= temp->getEmployee().age && temp->getEmployee().age <= maxAge) {
						maxInc = max(maxInc, temp->getEmployee().income);
						temp = temp->getRight();
					}
					else if (temp->getEmployee().age > maxAge)
						temp = temp->getLeft();
					else temp = temp->getRight();
				}
			}

			currentPtr = nullptr;
		}
	}
	return maxInc;
}


double Queries::MaxPerf(int minAge, int maxAge, BST bst) {
	double maxPerf = 0;
	Node* currentPtr = bst.getRoot();

	while (currentPtr != nullptr) {
		if (currentPtr->getEmployee().age < minAge)
			currentPtr = currentPtr->getRight();

		else if (currentPtr->getEmployee().age > maxAge)
			currentPtr = currentPtr->getLeft();
		else {
			maxPerf = max(maxPerf, currentPtr->getEmployee().performance);
			if (currentPtr->getRight() != nullptr) {
				Node* temp = currentPtr->getRight();
				while (temp != nullptr) {
					if (minAge <= temp->getEmployee().age && temp->getEmployee().age <= maxAge) {
						maxPerf = max(maxPerf, temp->getEmployee().performance);
						temp = temp->getLeft();
					}
					else if (temp->getEmployee().age < minAge)
						temp = temp->getRight();
					else temp = temp->getLeft();
				}
			}

			if (currentPtr->getLeft() != nullptr) {
				Node* temp = currentPtr->getLeft();
				while (temp != nullptr) {
					if (minAge <= temp->getEmployee().age && temp->getEmployee().age <= maxAge) {
						maxPerf = max(maxPerf, temp->getEmployee().performance);
						temp = temp->getRight();
					}
					else if (temp->getEmployee().age > maxAge)
						temp = temp->getLeft();
					else temp = temp->getRight();
				}
			}

			currentPtr = nullptr;
		}
	}
	return maxPerf;
}

double Queries::MinIncome(int minAge, int maxAge, BST bst) {
	double minInc = 10000.0;
	Node* currentPtr = bst.getRoot();

	while (currentPtr != nullptr) {
		if (currentPtr->getEmployee().age < minAge)
			currentPtr = currentPtr->getRight();

		else if (currentPtr->getEmployee().age > maxAge)
			currentPtr = currentPtr->getLeft();
		else {
			minInc = min(minInc, currentPtr->getEmployee().income);
			if (currentPtr->getRight() != nullptr) {
				Node* temp = currentPtr->getRight();
				while (temp != nullptr) {
					if (minAge <= temp->getEmployee().age && temp->getEmployee().age <= maxAge) {
						minInc = min(minInc, temp->getEmployee().income);
						temp = temp->getLeft();
					}
					else if (temp->getEmployee().age < minAge)
						temp = temp->getRight();
					else temp = temp->getLeft();
				}
			}

			if (currentPtr->getLeft() != nullptr) {
				Node* temp = currentPtr->getLeft();
				while (temp != nullptr) {
					if (minAge <= temp->getEmployee().age && temp->getEmployee().age <= maxAge) {
						minInc = min(minInc, temp->getEmployee().income);
						temp = temp->getRight();
					}
					else if (temp->getEmployee().age > maxAge)
						temp = temp->getLeft();
					else temp = temp->getRight();
				}
			}

			currentPtr = nullptr;
		}
	}
	return minInc;
}


double Queries::MinPerf(int minAge, int maxAge, BST bst) {
	double minPerf = 10000.0;
	Node* currentPtr = bst.getRoot();

	while (currentPtr != nullptr) {
		if (currentPtr->getEmployee().age < minAge)
			currentPtr = currentPtr->getRight();

		else if (currentPtr->getEmployee().age > maxAge)
			currentPtr = currentPtr->getLeft();
		else {
			minPerf = min(minPerf, currentPtr->getEmployee().performance);
			if (currentPtr->getRight() != nullptr) {
				Node* temp = currentPtr->getRight();
				while (temp != nullptr) {
					if (minAge <= temp->getEmployee().age && temp->getEmployee().age <= maxAge) {
						minPerf = min(minPerf, temp->getEmployee().performance);
						temp = temp->getLeft();
					}
					else if (temp->getEmployee().age < minAge)
						temp = temp->getRight();
					else temp = temp->getLeft();
				}
			}

			if (currentPtr->getLeft() != nullptr) {
				Node* temp = currentPtr->getLeft();
				while (temp != nullptr) {
					if (minAge <= temp->getEmployee().age && temp->getEmployee().age <= maxAge) {
						minPerf = min(minPerf, temp->getEmployee().performance);
						temp = temp->getRight();
					}
					else if (temp->getEmployee().age > maxAge)
						temp = temp->getLeft();
					else temp = temp->getRight();
				}
			}

			currentPtr = nullptr;
		}
	}
	return minPerf;
}

void Queries:: collectTopKNodes(Node* root, int minAge, int maxAge, int K, bool isIncomeQuery, PriorityQueue& pq)
{
	if (root == nullptr) return;

        double age = root->getEmployee().age;
        if (age >= minAge && age <= maxAge) {
            if (pq.isEmpty() || pq.getsize() < K) {
                if (isIncomeQuery) {
                    pq.push(root->getEmployee().income);
                } else {
                    pq.push(root->getEmployee().performance);
                }
            } else {
                int currentValue = (isIncomeQuery) ? root->getEmployee().income : root->getEmployee().performance;
                int topValue = pq.top();

                if (currentValue > topValue) {
                    pq.pop();
                    pq.push(currentValue);
                }
            }
        }

        collectTopKNodes(root->getLeft(), minAge, maxAge, K, isIncomeQuery, pq);
        collectTopKNodes(root->getRight(), minAge, maxAge, K, isIncomeQuery, pq);
}

void Queries::TopKNodes(int minAge, int maxAge, int K, bool isIncomeQuery, BST bst) {
        PriorityQueue pq(K);

        collectTopKNodes(bst.getRoot(), minAge, maxAge, K, isIncomeQuery, pq);

        cout << "Top " << K << " Nodes:" << endl;
        while (!pq.isEmpty()) {
            int topValue = pq.top();
            pq.pop();

            if (isIncomeQuery) {
                cout << "Income: " << topValue << endl;
            } else {
                cout << "Performance: " << topValue << endl;
            }
        }
    }