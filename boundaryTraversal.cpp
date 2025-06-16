#include <iostream>
#include <vector>
using namespace std;

// Function to check if a given node is a leaf node
bool isLeaf(int index, int n) {
    return (index >= n / 2 && index < n);
}

// Function to print the left boundary excluding leaf nodes
void printLeftBoundary(const vector<int>& tree, int n, vector<int>& boundary) {
    int index = 0;
    while (index < n) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        if (leftIndex < n && !isLeaf(leftIndex, n)) {
            boundary.push_back(tree[leftIndex]);
            index = leftIndex;
        } else if (rightIndex < n && !isLeaf(rightIndex, n)) {
            boundary.push_back(tree[rightIndex]);
            index = rightIndex;
        } else {
            break;
        }
    }
}

// Function to print all leaf nodes
void printLeaves(const vector<int>& tree, int n, vector<int>& boundary) {
    for (int i = 0; i < n; ++i) {
        if (isLeaf(i, n)) {
            boundary.push_back(tree[i]);
        }
    }
}

// Function to print the right boundary excluding leaf nodes
void printRightBoundary(const vector<int>& tree, int n, vector<int>& boundary) {
    vector<int> rightBoundary;
    int index = 0;
    while (index < n) {
        int rightIndex = 2 * index + 2;
        int leftIndex = 2 * index + 1;

        if (rightIndex < n && !isLeaf(rightIndex, n)) {
            rightBoundary.push_back(tree[rightIndex]);
            index = rightIndex;
        } else if (leftIndex < n && !isLeaf(leftIndex, n)) {
            rightBoundary.push_back(tree[leftIndex]);
            index = leftIndex;
        } else {
            break;
        }
    }
    // Add right boundary nodes to the boundary in reverse order
    for (auto it = rightBoundary.rbegin(); it != rightBoundary.rend(); ++it) {
        boundary.push_back(*it);
    }
}

// Main function to perform boundary traversal
vector<int> boundaryTraversal(const vector<int>& tree) {
    vector<int> boundary;
    int n = tree.size();
    if (n == 0) return boundary;

    // Add root node
    boundary.push_back(tree[0]);

    // Print the left boundary excluding the leaf nodes
    printLeftBoundary(tree, n, boundary);

    // Print all leaf nodes
    printLeaves(tree, n, boundary);

    // Print the right boundary excluding the leaf nodes
    printRightBoundary(tree, n, boundary);

    return boundary;
}

int main() {
    // Create a sample binary tree represented as an array
    vector<int> tree = {20, 8, 22, 4, 12, -1, 25, -1, -1, 10, 14};

    vector<int> boundary = boundaryTraversal(tree);

    // Print the boundary traversal
    for (int val : boundary) {
        cout << val << " ";
    }

    return 0;
}
