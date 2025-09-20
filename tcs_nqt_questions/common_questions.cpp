/**
 * Common TCS NQT Questions from 2021-2024 Batches
 * File contains implementation and solutions for common coding questions 
 * that frequently appear in TCS NQT examinations
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/**
 * Common Question 1: Find the Nth term in a series
 * This pattern-based question appears frequently in TCS NQT
 */
int findNthTermInSeries(int n, const string& seriesType) {
    if (seriesType == "square") {
        // 1, 4, 9, 16, 25, ...
        return n * n;
    } else if (seriesType == "cube") {
        // 1, 8, 27, 64, 125, ...
        return n * n * n;
    } else if (seriesType == "fibonacci") {
        // 0, 1, 1, 2, 3, 5, 8, 13, ...
        if (n <= 1) return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    } else if (seriesType == "prime") {
        // 2, 3, 5, 7, 11, 13, ...
        vector<int> primes;
        int num = 2;
        while (primes.size() < n) {
            bool isPrime = true;
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primes.push_back(num);
            }
            num++;
        }
        return primes.back();
    } else if (seriesType == "custom1") {
        // 3, 8, 15, 24, 35, ... (n^2 + 2n)
        return n * n + 2 * n;
    }
    
    return -1; // Invalid series type
}

/**
 * Common Question 2: String Manipulations
 * String manipulation problems are very common in TCS NQT
 */
string reverseWords(string s) {
    int start = 0;
    for (int end = 0; end <= s.length(); ++end) {
        if (end == s.length() || s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
    return s;
}

string removeVowels(string str) {
    string result = "";
    for (char c : str) {
        char lower = tolower(c);
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            result += c;
        }
    }
    return result;
}

/**
 * Common Question 3: Array Operations
 * Array manipulation problems are common in TCS NQT
 */
vector<int> rotateArray(vector<int> arr, int k, string direction) {
    int n = arr.size();
    k = k % n; // In case k > n
    
    if (direction == "right") {
        // Right rotation
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    } else {
        // Left rotation
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
    }
    
    return arr;
}

int findMissingNumber(vector<int> arr) {
    int n = arr.size() + 1; // Size should be n-1 for numbers 1 to n
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    
    for (int num : arr) {
        actualSum += num;
    }
    
    return expectedSum - actualSum;
}

/**
 * Common Question 4: Number Conversions
 * Number conversion problems are common in TCS NQT
 */
string decimalToBinary(int n) {
    if (n == 0) return "0";
    
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    
    return binary;
}

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    
    return decimal;
}

/**
 * Common Question 5: Dynamic Programming
 * DP problems are increasingly common in recent TCS NQT papers
 */
int knapsack(vector<int> weights, vector<int> values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            // If current item weight is less than capacity, we have two choices
            if (weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w]; // Can't include current item
            }
        }
    }
    
    return dp[n][capacity];
}

int longestCommonSubsequence(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

// Main function to demonstrate all solutions
int main() {
    cout << "Common TCS NQT Questions from 2021-2024 Batches\n";
    cout << "------------------------------------------------\n\n";
    
    // Common Question 1 demonstration
    cout << "Common Question 1: Find the Nth term in a series\n";
    cout << "10th term in square series: " << findNthTermInSeries(10, "square") << endl;
    cout << "8th term in fibonacci series: " << findNthTermInSeries(8, "fibonacci") << endl;
    cout << "5th term in prime series: " << findNthTermInSeries(5, "prime") << endl;
    cout << "6th term in custom series (n^2 + 2n): " << findNthTermInSeries(6, "custom1") << endl << endl;
    
    // Common Question 2 demonstration
    cout << "Common Question 2: String Manipulations\n";
    string str1 = "Hello TCS National Qualifier Test";
    cout << "Original string: \"" << str1 << "\"\n";
    cout << "Reversed words: \"" << reverseWords(str1) << "\"\n";
    cout << "After removing vowels: \"" << removeVowels(str1) << "\"\n\n";
    
    // Common Question 3 demonstration
    cout << "Common Question 3: Array Operations\n";
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> rotatedRight = rotateArray(arr, 2, "right");
    cout << "Array after right rotation by 2: ";
    for (int num : rotatedRight) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> missingArr = {1, 2, 4, 5, 6};
    cout << "Array with a missing number: ";
    for (int num : missingArr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Missing number: " << findMissingNumber(missingArr) << endl << endl;
    
    // Common Question 4 demonstration
    cout << "Common Question 4: Number Conversions\n";
    int decimal = 42;
    cout << "Decimal: " << decimal << " => Binary: " << decimalToBinary(decimal) << endl;
    string binary = "101010";
    cout << "Binary: " << binary << " => Decimal: " << binaryToDecimal(binary) << endl << endl;
    
    // Common Question 5 demonstration
    cout << "Common Question 5: Dynamic Programming\n";
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 8;
    cout << "Knapsack problem - Maximum value: " << knapsack(weights, values, capacity) << endl;
    
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout << "Longest Common Subsequence of \"" << s1 << "\" and \"" << s2 << "\": " 
         << longestCommonSubsequence(s1, s2) << endl;
    
    return 0;
}