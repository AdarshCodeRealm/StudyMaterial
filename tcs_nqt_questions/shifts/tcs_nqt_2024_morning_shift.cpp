/**
 * TCS NQT 2024 Morning Shift Questions with Solutions
 * File contains implementation and solutions for TCS NQT 2024 Morning Shift coding questions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/**
 * Question 1: Travelling Salesman Problem (Simplified)
 * Given a set of cities and the distances between them, 
 * find the shortest possible route that visits each city exactly once and returns to the origin city.
 */
int tspNearestNeighbor(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    int result = 0;
    
    // Start from vertex 0
    int current = 0;
    visited[0] = true;
    
    // Visit n-1 cities
    for (int i = 0; i < n - 1; i++) {
        int next = -1;
        int minDist = INT_MAX;
        
        // Find nearest unvisited city
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[current][j] < minDist) {
                next = j;
                minDist = graph[current][j];
            }
        }
        
        visited[next] = true;
        result += minDist;
        current = next;
    }
    
    // Return to the origin city
    result += graph[current][0];
    
    return result;
}

/**
 * Question 2: Height of Binary Tree
 * Find the height (depth) of a binary tree
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int heightOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    
    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

/**
 * Question 3: Minimum Number of Swaps to Sort Array
 * Find the minimum number of swaps required to sort an array in ascending order
 */
int minSwapsToSort(vector<int> arr) {
    int n = arr.size();
    
    // Create a vector of pairs where first element is the array element
    // and second element is its position
    vector<pair<int, int>> arrPos(n);
    for (int i = 0; i < n; i++) {
        arrPos[i] = {arr[i], i};
    }
    
    // Sort the array based on values
    sort(arrPos.begin(), arrPos.end());
    
    // Initialize visited and count of swaps
    vector<bool> visited(n, false);
    int swaps = 0;
    
    for (int i = 0; i < n; i++) {
        // If element is already visited or at its correct position
        if (visited[i] || arrPos[i].second == i)
            continue;
        
        // Find the cycle size
        int cycleSize = 0;
        int j = i;
        
        while (!visited[j]) {
            visited[j] = true;
            
            j = arrPos[j].second;
            cycleSize++;
        }
        
        // Update swap count
        swaps += cycleSize - 1;
    }
    
    return swaps;
}

// Main function to demonstrate all solutions
int main() {
    cout << "TCS NQT 2024 Morning Shift Questions and Solutions\n";
    cout << "------------------------------------------------\n\n";
    
    // Question 1 demonstration
    cout << "Question 1: Travelling Salesman Problem (Simplified)\n";
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    cout << "Distance matrix:\n";
    for (const auto& row : graph) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Shortest tour length (using nearest neighbor heuristic): " << tspNearestNeighbor(graph) << endl << endl;
    
    // Question 2 demonstration
    cout << "Question 2: Height of Binary Tree\n";
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Height of the binary tree: " << heightOfBinaryTree(root) << endl << endl;
    
    // Question 3 demonstration
    cout << "Question 3: Minimum Number of Swaps to Sort Array\n";
    vector<int> arr = {1, 5, 4, 3, 2};
    cout << "Array: {1, 5, 4, 3, 2}\n";
    cout << "Minimum number of swaps required to sort: " << minSwapsToSort(arr) << endl;
    
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}