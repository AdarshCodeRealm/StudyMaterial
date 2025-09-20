/**
 * TCS NQT 2021 Evening Shift Questions with Solutions
 * File contains implementation and solutions for TCS NQT 2021 Evening Shift coding questions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

/**
 * Question 1: Train Problem
 * A train is moving at a speed of X km/hr. Find the time taken by the train 
 * to cross a platform of length Y meters.
 */
double trainPlatformProblem(double trainLength, double platformLength, double speed) {
    // Convert speed from km/hr to m/s
    double speedMPS = speed * (5.0 / 18.0);
    
    // Time = Distance / Speed
    // Distance is train length + platform length (in meters)
    return (trainLength + platformLength) / speedMPS;
}

/**
 * Question 2: Array Manipulations
 * Find the smallest positive number missing from an unsorted array
 */
int findSmallestMissingPositive(vector<int>& nums) {
    int n = nums.size();
    
    // Mark elements that are out of range or negative as n+1
    for(int i = 0; i < n; i++) {
        if(nums[i] <= 0 || nums[i] > n) {
            nums[i] = n + 1;
        }
    }
    
    // Mark visited indices
    for(int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        if(num <= n) {
            nums[num-1] = -abs(nums[num-1]);
        }
    }
    
    // Find first positive number
    for(int i = 0; i < n; i++) {
        if(nums[i] > 0) {
            return i + 1;
        }
    }
    
    return n + 1;
}

/**
 * Question 3: String Encryption
 * Implement a string encryption algorithm where each character is replaced by its 
 * next alphabet and vowels are replaced by their ASCII values
 */
string encryptString(const string& input) {
    string result = "";
    for (char c : input) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char next = (c - base + 1) % 26 + base;
            
            // Check if next character is a vowel
            char lower = tolower(next);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                result += to_string(int(next));
            } else {
                result += next;
            }
        } else {
            result += c;
        }
    }
    return result;
}

// Main function to demonstrate all solutions
int main() {
    cout << "TCS NQT 2021 Evening Shift Questions and Solutions\n";
    cout << "------------------------------------------------\n\n";
    
    // Question 1 demonstration
    cout << "Question 1: Train Problem\n";
    double trainLength = 150.0; // in meters
    double platformLength = 250.0; // in meters
    double trainSpeed = 72.0; // in km/hr
    cout << "Train length: " << trainLength << " m, Platform length: " << platformLength << " m, Train speed: " << trainSpeed << " km/hr\n";
    cout << "Time taken to cross the platform: " << trainPlatformProblem(trainLength, platformLength, trainSpeed) << " seconds\n\n";
    
    // Question 2 demonstration
    cout << "Question 2: Array Manipulations\n";
    vector<int> arr = {1, 3, 6, 4, 1, 2};
    cout << "Array: {1, 3, 6, 4, 1, 2}\n";
    vector<int> arrCopy = arr;
    cout << "Smallest missing positive number: " << findSmallestMissingPositive(arrCopy) << endl << endl;
    
    // Question 3 demonstration
    cout << "Question 3: String Encryption\n";
    string str = "Hello World";
    cout << "Original string: \"" << str << "\"\n";
    cout << "Encrypted string: \"" << encryptString(str) << "\"\n";
    
    return 0;
}