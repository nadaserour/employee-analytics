#include "Queries.hpp"
#include "bst.hpp"
#include "Node.hpp"
#include <iostream>
using namespace std;

void Queries:: sumAndCountInc(Node* root, int minAge, int maxAge, double& sum, int& count) {
	if (root == nullptr) return;

	if (root->getAge() > minAge) sumAndCountInc(root->getLeft(), minAge, maxAge, sum, count);

	if (root->getAge() >= minAge && root->getAge() <= maxAge) {
		sum += root->getIncome();
		count++;
	}
	if (root->getAge() < maxAge) sumAndCountInc(root->getRight(), minAge, maxAge, sum, count);
}

void Queries::sumAndCountPerf(Node* root, int minAge, int maxAge, double& sum, int& count) {
	if (root == nullptr) return;

	if (root->getAge() > minAge) sumAndCountPerf(root->getLeft(), minAge, maxAge, sum, count);

	if (root->getAge() >= minAge && root->getAge() <= maxAge) {
		sum += root->getPerformance();
		count++;
	}
	if (root->getAge() < maxAge) sumAndCountPerf(root->getRight(), minAge, maxAge, sum, count);
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
		if (currentPtr->getAge() < minAge)
			currentPtr = currentPtr->getRight();

		else if (currentPtr->getAge() > maxAge)
			currentPtr = currentPtr->getLeft();
		else {
			maxInc = max(maxInc, currentPtr->getIncome());
			if (currentPtr->getRight() != nullptr) {
				Node* temp = currentPtr->getRight();
				while (temp != nullptr) {
					if (minAge <= temp->getAge() && temp->getAge() <= maxAge) {
						maxInc = max(maxInc, temp->getIncome());
						temp = temp->getLeft();
					}
					else if (temp->getAge() < minAge)
						temp = temp->getRight();
					else temp = temp->getLeft();
				}
			}

			if (currentPtr->getLeft() != nullptr) {
				Node* temp = currentPtr->getLeft();
				while (temp != nullptr) {
					if (minAge <= temp->getAge() && temp->getAge() <= maxAge) {
						maxInc = max(maxInc, temp->getIncome());
						temp = temp->getRight();
					}
					else if (temp->getAge() > maxAge)
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
		if (currentPtr->getAge() < minAge)
			currentPtr = currentPtr->getRight();

		else if (currentPtr->getAge() > maxAge)
			currentPtr = currentPtr->getLeft();
		else {
			maxPerf = max(maxPerf, currentPtr->getPerformance());
			if (currentPtr->getRight() != nullptr) {
				Node* temp = currentPtr->getRight();
				while (temp != nullptr) {
					if (minAge <= temp->getAge() && temp->getAge() <= maxAge) {
						maxPerf = max(maxPerf, temp->getPerformance());
						temp = temp->getLeft();
					}
					else if (temp->getAge() < minAge)
						temp = temp->getRight();
					else temp = temp->getLeft();
				}
			}

			if (currentPtr->getLeft() != nullptr) {
				Node* temp = currentPtr->getLeft();
				while (temp != nullptr) {
					if (minAge <= temp->getAge() && temp->getAge() <= maxAge) {
						maxPerf = max(maxPerf, temp->getPerformance());
						temp = temp->getRight();
					}
					else if (temp->getAge() > maxAge)
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
		if (currentPtr->getAge() < minAge)
			currentPtr = currentPtr->getRight();

		else if (currentPtr->getAge() > maxAge)
			currentPtr = currentPtr->getLeft();
		else {
			minInc = min(minInc, currentPtr->getIncome());
			if (currentPtr->getRight() != nullptr) {
				Node* temp = currentPtr->getRight();
				while (temp != nullptr) {
					if (minAge <= temp->getAge() && temp->getAge() <= maxAge) {
						minInc = min(minInc, temp->getIncome());
						temp = temp->getLeft();
					}
					else if (temp->getAge() < minAge)
						temp = temp->getRight();
					else temp = temp->getLeft();
				}
			}

			if (currentPtr->getLeft() != nullptr) {
				Node* temp = currentPtr->getLeft();
				while (temp != nullptr) {
					if (minAge <= temp->getAge() && temp->getAge() <= maxAge) {
						minInc = min(minInc, temp->getIncome());
						temp = temp->getRight();
					}
					else if (temp->getAge() > maxAge)
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
		if (currentPtr->getAge() < minAge)
			currentPtr = currentPtr->getRight();

		else if (currentPtr->getAge() > maxAge)
			currentPtr = currentPtr->getLeft();
		else {
			minPerf = min(minPerf, currentPtr->getPerformance());
			if (currentPtr->getRight() != nullptr) {
				Node* temp = currentPtr->getRight();
				while (temp != nullptr) {
					if (minAge <= temp->getAge() && temp->getAge() <= maxAge) {
						minPerf = min(minPerf, temp->getPerformance());
						temp = temp->getLeft();
					}
					else if (temp->getAge() < minAge)
						temp = temp->getRight();
					else temp = temp->getLeft();
				}
			}

			if (currentPtr->getLeft() != nullptr) {
				Node* temp = currentPtr->getLeft();
				while (temp != nullptr) {
					if (minAge <= temp->getAge() && temp->getAge() <= maxAge) {
						minPerf = min(minPerf, temp->getPerformance());
						temp = temp->getRight();
					}
					else if (temp->getAge() > maxAge)
						temp = temp->getLeft();
					else temp = temp->getRight();
				}
			}

			currentPtr = nullptr;
		}
	}
	return minPerf;
}

