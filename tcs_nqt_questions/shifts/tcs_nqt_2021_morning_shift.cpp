/**
 * TCS NQT 2021 Morning Shift Questions with Solutions
 * File contains implementation and solutions for TCS NQT 2021 Morning Shift coding questions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

/**
 * Question 1: Number Series Problem
 * Find the Nth term in the given series: 3, 8, 15, 24, 35, ...
 */
int numberSeriesProblem(int n) {
    // Pattern: (n+1)^2 - 1
    return (n + 1) * (n + 1) - 1;
}

/**
 * Question 2: Sub-array with given sum
 * Find a continuous sub-array which adds to a given sum S
 */
vector<int> subArrayWithGivenSum(vector<int> arr, int S) {
    int n = arr.size();
    int currentSum = arr[0], start = 0;
    
    for (int i = 1; i <= n; i++) {
        while (currentSum > S && start < i-1) {
            currentSum = currentSum - arr[start];
            start++;
        }
        
        if (currentSum == S) {
            return {start, i-1};
        }
        
        if (i < n)
            currentSum += arr[i];
    }
    
    return {-1}; // No subarray found
}

/**
 * Question 3: String Operations Problem
 * Count vowels and consonants in a given string
 */
pair<int, int> countVowelsConsonants(string str) {
    int vowels = 0, consonants = 0;
    
    for (char c : str) {
        if (isalpha(c)) {
            char ch = tolower(c);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    
    return {vowels, consonants};
}

// Main function to demonstrate all solutions
int main() {
    cout << "TCS NQT 2021 Morning Shift Questions and Solutions\n";
    cout << "------------------------------------------------\n\n";
    
    // Question 1 demonstration
    cout << "Question 1: Number Series Problem\n";
    cout << "Find the Nth term in the given series: 3, 8, 15, 24, 35, ...\n";
    cout << "5th term: " << numberSeriesProblem(5) << endl;
    cout << "7th term: " << numberSeriesProblem(7) << endl << endl;
    
    // Question 2 demonstration
    cout << "Question 2: Sub-array with given sum\n";
    vector<int> arr = {1, 2, 3, 7, 5};
    int sum = 12;
    cout << "Array: {1, 2, 3, 7, 5}, Sum: 12\n";
    vector<int> result = subArrayWithGivenSum(arr, sum);
    if (result[0] != -1)
        cout << "Subarray found from index " << result[0] << " to " << result[1] << endl << endl;
    else
        cout << "No subarray found with given sum\n\n";
    
    // Question 3 demonstration
    cout << "Question 3: String Operations Problem\n";
    string str = "TCS National Qualifier Test";
    cout << "String: \"" << str << "\"\n";
    pair<int, int> counts = countVowelsConsonants(str);
    cout << "Vowels: " << counts.first << ", Consonants: " << counts.second << endl;
    
    return 0;
}