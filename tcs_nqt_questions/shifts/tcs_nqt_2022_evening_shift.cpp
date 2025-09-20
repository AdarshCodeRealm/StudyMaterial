/**
 * TCS NQT 2022 Evening Shift Questions with Solutions
 * File contains implementation and solutions for TCS NQT 2022 Evening Shift coding questions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

/**
 * Question 1: Jumping Numbers
 * A number is called a jumping number if all adjacent digits in it differ by 1.
 * Find the Nth jumping number.
 */
bool isJumpingNumber(int num) {
    if (num <= 10) return true;
    
    string str = to_string(num);
    for (int i = 0; i < str.length() - 1; i++) {
        if (abs(str[i] - str[i+1]) != 1) {
            return false;
        }
    }
    return true;
}

int findNthJumpingNumber(int n) {
    if (n <= 10) return n;
    
    int count = 10; // First 10 numbers (0-9) are jumping numbers
    int num = 10;
    
    while (count < n) {
        num++;
        if (isJumpingNumber(num)) {
            count++;
        }
    }
    
    return num;
}

/**
 * Question 2: Job Sequencing Problem
 * Given an array of jobs with deadlines and profits, find the maximum profit
 * that can be earned by scheduling jobs optimally
 */
struct Job {
    int id, deadline, profit;
};

bool compareJobs(Job a, Job b) {
    return a.profit > b.profit;
}

int maxProfitJobSequencing(vector<Job> jobs) {
    // Sort jobs based on profit (descending)
    sort(jobs.begin(), jobs.end(), compareJobs);
    
    // Find the maximum deadline
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    // Initialize the slots to false (not occupied)
    vector<bool> slot(maxDeadline + 1, false);
    
    int totalProfit = 0;
    int jobsScheduled = 0;
    
    // Process jobs one by one
    for (const auto& job : jobs) {
        // Find a free slot for this job
        for (int i = min(maxDeadline, job.deadline); i > 0; i--) {
            if (!slot[i]) {
                slot[i] = true;
                totalProfit += job.profit;
                jobsScheduled++;
                break;
            }
        }
    }
    
    return totalProfit;
}

/**
 * Question 3: String Pattern Matching
 * Check if a given string follows a specific pattern
 */
bool followsPattern(const string& str, const string& pattern) {
    unordered_map<char, string> charToStr;
    unordered_set<string> usedStrs;
    
    int i = 0;
    for (char c : pattern) {
        if (i >= str.length()) return false;
        
        // Try to match the next part of the string with this pattern character
        if (charToStr.find(c) != charToStr.end()) {
            // This pattern character has been seen before
            string mappedStr = charToStr[c];
            
            // Check if the current portion of str matches the mapped string
            if (i + mappedStr.length() > str.length() || 
                str.substr(i, mappedStr.length()) != mappedStr) {
                return false;
            }
            
            i += mappedStr.length();
        } else {
            // This is a new pattern character
            // Try different lengths for this mapping
            for (int len = 1; i + len <= str.length(); len++) {
                string candidate = str.substr(i, len);
                
                // Check if this candidate is already mapped to another pattern char
                if (usedStrs.find(candidate) != usedStrs.end()) continue;
                
                // Try this mapping
                charToStr[c] = candidate;
                usedStrs.insert(candidate);
                
                i += len;
                break;
            }
            
            // If we couldn't find a mapping, return false
            if (charToStr.find(c) == charToStr.end()) {
                return false;
            }
        }
    }
    
    // Make sure we've consumed the entire string
    return i == str.length();
}

// Main function to demonstrate all solutions
int main() {
    cout << "TCS NQT 2022 Evening Shift Questions and Solutions\n";
    cout << "------------------------------------------------\n\n";
    
    // Question 1 demonstration
    cout << "Question 1: Jumping Numbers\n";
    int n = 20;
    cout << "The " << n << "th jumping number is: " << findNthJumpingNumber(n) << endl << endl;
    
    // Question 2 demonstration
    cout << "Question 2: Job Sequencing Problem\n";
    vector<Job> jobs = {
        {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}
    };
    cout << "Maximum profit: " << maxProfitJobSequencing(jobs) << endl << endl;
    
    // Question 3 demonstration
    cout << "Question 3: String Pattern Matching\n";
    string str = "redblueredblue";
    string pattern = "abab";
    cout << "String: \"" << str << "\", Pattern: \"" << pattern << "\"\n";
    cout << "String follows pattern: " << (followsPattern(str, pattern) ? "True" : "False") << endl;
    
    return 0;
}