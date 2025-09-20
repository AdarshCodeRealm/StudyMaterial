/**
 * TCS NQT 2024 Evening Shift Questions with Solutions
 * File contains implementation and solutions for TCS NQT 2024 Evening Shift coding questions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * Question 1: Rearrange Array in Wave Pattern
 * Given an array, rearrange it in a wave-like pattern (a1 >= a2 <= a3 >= a4 <= ...)
 */
void waveSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i += 2) {
        // If current element is smaller than previous element
        if (i > 0 && arr[i - 1] < arr[i]) {
            swap(arr[i], arr[i - 1]);
        }
        
        // If current element is smaller than next element
        if (i < n - 1 && arr[i] < arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

/**
 * Question 2: Stock Buy and Sell Problem
 * Given stock prices for different days, find the maximum profit that can be earned
 */
int maxProfit(const vector<int>& prices) {
    int totalProfit = 0;
    
    for (int i = 1; i < prices.size(); i++) {
        // If current price is higher than previous day, we can make a profit
        if (prices[i] > prices[i - 1]) {
            totalProfit += prices[i] - prices[i - 1];
        }
    }
    
    return totalProfit;
}

/**
 * Question 3: Word Break Problem
 * Given a string and a dictionary of words, determine if the string can be segmented 
 * into a space-separated sequence of dictionary words
 */
bool wordBreak(const string& s, const vector<string>& wordDict) {
    set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.length();
    
    // dp[i] represents whether the substring s[0...i-1] can be segmented
    vector<bool> dp(n + 1, false);
    dp[0] = true; // Empty string can be segmented
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}

// Main function to demonstrate all solutions
int main() {
    cout << "TCS NQT 2024 Evening Shift Questions and Solutions\n";
    cout << "------------------------------------------------\n\n";
    
    // Question 1 demonstration
    cout << "Question 1: Rearrange Array in Wave Pattern\n";
    vector<int> arr = {10, 5, 6, 3, 2, 20, 100, 80};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    waveSort(arr);
    
    cout << "Wave sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    // Question 2 demonstration
    cout << "Question 2: Stock Buy and Sell Problem\n";
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << "Stock prices: ";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << endl;
    cout << "Maximum profit: " << maxProfit(prices) << endl << endl;
    
    // Question 3 demonstration
    cout << "Question 3: Word Break Problem\n";
    string s = "ilikeprogramming";
    vector<string> wordDict = {"i", "like", "program", "programming", "ming"};
    cout << "String: \"" << s << "\"\n";
    cout << "Dictionary: ";
    for (const auto& word : wordDict) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;
    cout << "Can be segmented: " << (wordBreak(s, wordDict) ? "Yes" : "No") << endl;
    
    return 0;
}