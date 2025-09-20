/**
 * TCS NQT 2023 Morning Shift Questions with Solutions
 * File contains implementation and solutions for TCS NQT 2023 Morning Shift coding questions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/**
 * Question 1: Matrix Operations
 * Given a square matrix of size n*n, calculate the absolute difference 
 * between the sum of its diagonals.
 */
int diagonalDifference(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    
    for (int i = 0; i < n; i++) {
        primaryDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][n - 1 - i];
    }
    
    return abs(primaryDiagonalSum - secondaryDiagonalSum);
}

/**
 * Question 2: Digit Removal Problem
 * Remove minimum number of digits from a given integer to make it divisible by another integer
 */
int minimumDigitsToRemove(int num, int divisor) {
    // If num is already divisible by divisor, return 0
    if (num % divisor == 0)
        return 0;
    
    string strNum = to_string(num);
    int n = strNum.length();
    
    // Try removing one digit at a time and check if resulting number is divisible by divisor
    for (int i = 0; i < n; i++) {
        string newStr = strNum.substr(0, i) + strNum.substr(i + 1);
        if (newStr.empty()) continue;
        
        int newNum = stoi(newStr);
        if (newNum % divisor == 0)
            return 1;
    }
    
    // Try removing two digits
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string newStr = strNum.substr(0, i) + strNum.substr(i + 1, j - i - 1) + strNum.substr(j + 1);
            if (newStr.empty()) continue;
            
            int newNum = stoi(newStr);
            if (newNum % divisor == 0)
                return 2;
        }
    }
    
    // Try larger numbers of digits to remove (implement as needed)
    // ...
    
    return -1; // If unable to make divisible by removing digits
}

/**
 * Question 3: Lexicographically Smallest String
 * Find the lexicographically smallest string after removing k characters
 */
string findLexSmallestString(string s, int k) {
    int n = s.length();
    if (k >= n)
        return "";
    
    // Use a stack to keep track of characters
    vector<char> stack;
    
    for (int i = 0; i < n; i++) {
        // Remove characters that are larger than current character
        while (!stack.empty() && k > 0 && stack.back() > s[i]) {
            stack.pop_back();
            k--;
        }
        stack.push_back(s[i]);
    }
    
    // If we still have characters to remove, remove from the end
    while (k > 0 && !stack.empty()) {
        stack.pop_back();
        k--;
    }
    
    // Construct the result
    string result = "";
    for (char c : stack) {
        result += c;
    }
    
    return result;
}

// Main function to demonstrate all solutions
int main() {
    cout << "TCS NQT 2023 Morning Shift Questions and Solutions\n";
    cout << "------------------------------------------------\n\n";
    
    // Question 1 demonstration
    cout << "Question 1: Matrix Operations\n";
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {9, 8, 9}
    };
    cout << "Matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Diagonal Difference: " << diagonalDifference(matrix) << endl << endl;
    
    // Question 2 demonstration
    cout << "Question 2: Digit Removal Problem\n";
    int num = 12345;
    int divisor = 3;
    cout << "Number: " << num << ", Divisor: " << divisor << endl;
    int result = minimumDigitsToRemove(num, divisor);
    if (result != -1)
        cout << "Minimum number of digits to remove: " << result << endl << endl;
    else
        cout << "Cannot make the number divisible by removing digits.\n\n";
    
    // Question 3 demonstration
    cout << "Question 3: Lexicographically Smallest String\n";
    string str = "abcdeca";
    int k = 2;
    cout << "Original string: \"" << str << "\", k = " << k << endl;
    cout << "Lexicographically smallest string after removing " << k << " characters: \"" 
         << findLexSmallestString(str, k) << "\"\n";
    
    return 0;
}