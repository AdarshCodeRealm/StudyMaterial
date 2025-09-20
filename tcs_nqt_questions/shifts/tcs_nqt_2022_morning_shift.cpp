/**
 * TCS NQT 2022 Morning Shift Questions with Solutions
 * File contains implementation and solutions for TCS NQT 2022 Morning Shift coding questions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * Question 1: Counting Binary Strings
 * Count the number of binary strings of length N that don't have consecutive 1s
 */
int countBinaryStrings(int n) {
    // a[i] = binary strings of length i ending in 0
    // b[i] = binary strings of length i ending in 1
    int a[n+1], b[n+1];
    
    a[1] = 1;  // Only "0" of length 1
    b[1] = 1;  // Only "1" of length 1
    
    for (int i = 2; i <= n; i++) {
        a[i] = a[i-1] + b[i-1];  // Can append 0 to both previous endings
        b[i] = a[i-1];           // Can append 1 only to strings ending with 0
    }
    
    return a[n] + b[n];
}

/**
 * Question 2: Frequency of Elements
 * Find the frequency of each element in a given array
 */
unordered_map<int, int> findFrequency(const vector<int>& arr) {
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }
    return freqMap;
}

/**
 * Question 3: Palindrome Check with Modification
 * Check if a string can be made a palindrome by removing at most one character
 */
bool canBePalindrome(const string& str) {
    int left = 0, right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            // Try removing character at left or right
            // Check if removing left character works
            bool skipLeft = true;
            int l = left + 1, r = right;
            while (l < r) {
                if (str[l] != str[r]) {
                    skipLeft = false;
                    break;
                }
                l++; r--;
            }
            
            // Check if removing right character works
            bool skipRight = true;
            l = left; r = right - 1;
            while (l < r) {
                if (str[l] != str[r]) {
                    skipRight = false;
                    break;
                }
                l++; r--;
            }
            
            return skipLeft || skipRight;
        }
        left++; right--;
    }
    
    // String is already a palindrome
    return true;
}

// Main function to demonstrate all solutions
int main() {
    cout << "TCS NQT 2022 Morning Shift Questions and Solutions\n";
    cout << "------------------------------------------------\n\n";
    
    // Question 1 demonstration
    cout << "Question 1: Counting Binary Strings\n";
    int n = 4;
    cout << "Count of binary strings of length " << n << " without consecutive 1's: " << countBinaryStrings(n) << endl << endl;
    
    // Question 2 demonstration
    cout << "Question 2: Frequency of Elements\n";
    vector<int> arr = {1, 2, 3, 1, 2, 1, 5, 1};
    cout << "Array: {1, 2, 3, 1, 2, 1, 5, 1}\n";
    cout << "Frequency of each element:\n";
    unordered_map<int, int> freqMap = findFrequency(arr);
    for (const auto& pair : freqMap) {
        cout << pair.first << " appears " << pair.second << " times\n";
    }
    cout << endl;
    
    // Question 3 demonstration
    cout << "Question 3: Palindrome Check with Modification\n";
    string str1 = "abca";
    string str2 = "abcd";
    cout << "String: \"" << str1 << "\" can be made palindrome by removing at most one character: " 
         << (canBePalindrome(str1) ? "True" : "False") << endl;
    cout << "String: \"" << str2 << "\" can be made palindrome by removing at most one character: " 
         << (canBePalindrome(str2) ? "True" : "False") << endl;
    
    return 0;
}