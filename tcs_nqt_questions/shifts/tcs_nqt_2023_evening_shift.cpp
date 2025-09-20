/**
 * TCS NQT 2023 Evening Shift Questions with Solutions
 * File contains implementation and solutions for TCS NQT 2023 Evening Shift coding questions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

/**
 * Question 1: Colorful Number
 * A number is said to be colorful if the product of every subset of consecutive digits
 * is different. Find if a number is colorful or not.
 */
bool isColorful(int num) {
    string numStr = to_string(num);
    unordered_set<int> products;
    
    for (int len = 1; len <= numStr.length(); len++) {
        for (int i = 0; i <= numStr.length() - len; i++) {
            int product = 1;
            for (int j = i; j < i + len; j++) {
                product *= (numStr[j] - '0');
            }
            
            if (products.find(product) != products.end()) {
                return false;
            }
            
            products.insert(product);
        }
    }
    
    return true;
}

/**
 * Question 2: Longest Increasing Subsequence
 * Find the length of the longest increasing subsequence of a given array
 */
int longestIncreasingSubsequence(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<int> dp(n, 1); // dp[i] = length of LIS ending at index i
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

/**
 * Question 3: Substring with Distinct Characters
 * Find the length of the longest substring with all distinct characters
 */
int longestSubstringWithDistinctChars(const string& s) {
    int n = s.length();
    if (n == 0) return 0;
    
    unordered_map<char, int> lastSeen;
    int maxLength = 0;
    int startIdx = 0;
    
    for (int i = 0; i < n; i++) {
        // If character is already in current window, update start index
        if (lastSeen.find(s[i]) != lastSeen.end() && lastSeen[s[i]] >= startIdx) {
            startIdx = lastSeen[s[i]] + 1;
        }
        
        // Update last seen position of current character
        lastSeen[s[i]] = i;
        
        // Update maximum length
        maxLength = max(maxLength, i - startIdx + 1);
    }
    
    return maxLength;
}

// Main function to demonstrate all solutions
int main() {
    cout << "TCS NQT 2023 Evening Shift Questions and Solutions\n";
    cout << "------------------------------------------------\n\n";
    
    // Question 1 demonstration
    cout << "Question 1: Colorful Number\n";
    int num1 = 3245;
    int num2 = 326;
    cout << num1 << " is " << (isColorful(num1) ? "colorful" : "not colorful") << endl;
    cout << num2 << " is " << (isColorful(num2) ? "colorful" : "not colorful") << endl << endl;
    
    // Question 2 demonstration
    cout << "Question 2: Longest Increasing Subsequence\n";
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Array: {10, 22, 9, 33, 21, 50, 41, 60}\n";
    cout << "Length of Longest Increasing Subsequence: " << longestIncreasingSubsequence(arr) << endl << endl;
    
    // Question 3 demonstration
    cout << "Question 3: Substring with Distinct Characters\n";
    string str1 = "abcabcbb";
    string str2 = "bbbbb";
    cout << "String: \"" << str1 << "\"\n";
    cout << "Length of longest substring with all distinct characters: " << longestSubstringWithDistinctChars(str1) << endl;
    cout << "String: \"" << str2 << "\"\n";
    cout << "Length of longest substring with all distinct characters: " << longestSubstringWithDistinctChars(str2) << endl;
    
    return 0;
}