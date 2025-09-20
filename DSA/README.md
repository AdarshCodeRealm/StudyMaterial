# Data Structures and Algorithms - Chapter 1: Essential Patterns

This repository contains comprehensive notes on 5 fundamental algorithmic patterns that are crucial for coding interviews and competitive programming.

## Table of Contents
1. [Two Pointers Pattern](#1-two-pointers-pattern)
2. [Fast & Slow Pointers Pattern](#2-fast--slow-pointers-pattern)
3. [Sliding Window Pattern](#3-sliding-window-pattern)
4. [Prefix Sum Pattern](#4-prefix-sum-pattern)
5. [Merge Intervals Pattern](#5-merge-intervals-pattern)

---

## 1. Two Pointers Pattern

### 📖 Overview
The Two Pointers technique involves using two pointers to traverse a data structure, typically an array or string. The pointers can move towards each other or in the same direction.

### 🎯 When to Use
- **Sorted Arrays**: Finding pairs, triplets, or ranges
- **Palindrome Problems**: Checking symmetry
- **Array Manipulation**: Removing duplicates, moving elements
- **Search Problems**: Finding target sums or differences

### 🔧 Common Approaches

#### 1. Opposite Direction (Convergent)
```
Left pointer starts at beginning, right pointer at end
Move towards each other based on conditions
```

#### 2. Same Direction (Parallel)
```
Both pointers move in same direction at different speeds
Often used for in-place modifications
```

### 💡 Template Code

```cpp
#include <vector>
#include <iostream>
using namespace std;

// Opposite Direction Template
vector<int> twoPointersOpposite(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        
        if (currentSum == target) {
            return {left, right};
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {-1, -1};
}

// Same Direction Template
int twoPointersSameDirection(vector<int>& arr) {
    int slow = 0, fast = 0;
    
    while (fast < arr.size()) {
        if (conditionMet(arr[fast])) {
            arr[slow] = arr[fast];
            slow++;
        }
        fast++;
    }
    
    return slow;
}
```

### 📝 Practice Problems

#### Problem 1: Two Sum II (Sorted Array)
**Problem**: Find two numbers that add up to target in sorted array
**Approach**: Use opposite direction pointers
**Time**: O(n), **Space**: O(1)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int currentSum = numbers[left] + numbers[right];
            if (currentSum == target) {
                return {left + 1, right + 1}; // 1-indexed
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {};
    }
};
```

#### Problem 2: Remove Duplicates from Sorted Array
**Problem**: Remove duplicates in-place from sorted array
**Approach**: Use same direction pointers
**Time**: O(n), **Space**: O(1)

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int slow = 1; // Position for next unique element
        
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        
        return slow;
    }
};
```

#### Problem 3: Valid Palindrome
**Problem**: Check if string is palindrome (ignoring case and non-alphanumeric)
**Approach**: Opposite direction pointers
**Time**: O(n), **Space**: O(1)

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};
```

### 🧠 Key Insights
- **Reduces Time Complexity**: Often reduces O(n²) to O(n)
- **Space Efficient**: Usually O(1) space complexity
- **Versatile**: Works with arrays, strings, linked lists

---

## 2. Fast & Slow Pointers Pattern

### 📖 Overview
Also known as the "Tortoise and Hare" algorithm, this pattern uses two pointers moving at different speeds to detect cycles, find middle elements, or solve specific traversal problems.

### 🎯 When to Use
- **Cycle Detection**: In linked lists or arrays
- **Finding Middle**: Of linked lists or arrays
- **Intersection Points**: Where cycles begin
- **Specific Positions**: Like nth from end

### 🔧 Speed Variations
- **Classic**: Slow moves 1 step, Fast moves 2 steps
- **Custom**: Different speed ratios based on problem

### 💡 Template Code

```cpp
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Cycle Detection Template
bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    
    ListNode *slow = head;
    ListNode *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

// Find Middle Template
ListNode* findMiddle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
```

### 📝 Practice Problems

#### Problem 1: Linked List Cycle
**Problem**: Detect if linked list has a cycle
**Approach**: Fast pointer moves 2 steps, slow moves 1
**Time**: O(n), **Space**: O(1)

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};
```

#### Problem 2: Find Cycle Start
**Problem**: Find where the cycle begins in linked list
**Approach**: Use Floyd's algorithm + mathematical proof
**Time**: O(n), **Space**: O(1)

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        // Phase 1: Detect cycle
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        if (!fast || !fast->next) return nullptr; // No cycle
        
        // Phase 2: Find start of cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
```

#### Problem 3: Happy Number
**Problem**: Determine if number is happy (sum of squares eventually becomes 1)
**Approach**: Treat as cycle detection in number sequence
**Time**: O(log n), **Space**: O(1)

```cpp
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        
        do {
            slow = getSumOfSquares(slow);
            fast = getSumOfSquares(getSumOfSquares(fast));
        } while (slow != fast);
        
        return slow == 1;
    }
    
private:
    int getSumOfSquares(int num) {
        int total = 0;
        while (num > 0) {
            int digit = num % 10;
            total += digit * digit;
            num /= 10;
        }
        return total;
    }
};
```

### 🧠 Key Insights
- **Mathematical Foundation**: Based on pigeonhole principle
- **Cycle Properties**: If cycle exists, fast will eventually catch slow
- **No Extra Space**: Achieves detection without additional data structures

---

## 3. Sliding Window Pattern

### 📖 Overview
The Sliding Window technique maintains a subset of elements (window) and slides it across the data structure to find optimal solutions efficiently.

### 🎯 When to Use
- **Subarray/Substring Problems**: Finding max, min, or specific conditions
- **Fixed/Variable Window Size**: Based on problem constraints
- **Optimization Problems**: Maximum/minimum in subarrays
- **Pattern Matching**: Character frequency, anagrams

### 🔧 Window Types

#### 1. Fixed Size Window
```cpp
#include <vector>
#include <algorithm>
using namespace std;

int fixedWindow(vector<int>& arr, int k) {
    if (arr.size() < k) return -1;
    
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;
    
    for (int i = k; i < arr.size(); i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

#### 2. Variable Size Window
```cpp
int variableWindow(vector<int>& arr, int target) {
    int left = 0;
    int windowSum = 0;
    int minLength = INT_MAX;
    
    for (int right = 0; right < arr.size(); right++) {
        windowSum += arr[right];
        
        while (windowSum >= target) {
            minLength = min(minLength, right - left + 1);
            windowSum -= arr[left];
            left++;
        }
    }
    
    return minLength == INT_MAX ? 0 : minLength;
}
```

### 💡 Template Code

```cpp
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// Generic Sliding Window Template
vector<int> slidingWindowTemplate(string s, string pattern) {
    int left = 0;
    unordered_map<char, int> charCount;
    vector<int> result;
    
    // Initialize character count
    for (char c : pattern) {
        charCount[c]++;
    }
    
    for (int right = 0; right < s.length(); right++) {
        // Expand window
        char rightChar = s[right];
        if (charCount.find(rightChar) != charCount.end()) {
            charCount[rightChar]--;
        }
        
        // Contract window when condition met
        while (windowConditionMet()) {
            // Update result
            result.push_back(left);
            
            // Shrink from left
            char leftChar = s[left];
            if (charCount.find(leftChar) != charCount.end()) {
                charCount[leftChar]++;
            }
            left++;
        }
    }
    
    return result;
}
```

### 📝 Practice Problems

#### Problem 1: Longest Substring Without Repeating Characters
**Problem**: Find length of longest substring without repeating characters
**Approach**: Variable size window with character tracking
**Time**: O(n), **Space**: O(min(m,n))

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (charIndex.find(s[right]) != charIndex.end() && 
                charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
```

#### Problem 2: Minimum Window Substring
**Problem**: Find minimum window substring containing all characters of pattern
**Approach**: Variable window with character frequency tracking
**Time**: O(|s| + |t|), **Space**: O(|s| + |t|)

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> dictT;
        for (char c : t) {
            dictT[c]++;
        }
        
        int required = dictT.size();
        int left = 0, right = 0;
        int formed = 0;
        unordered_map<char, int> windowCounts;
        
        int minLen = INT_MAX, minLeft = 0, minRight = 0;
        
        while (right < s.length()) {
            // Add character from right
            char character = s[right];
            windowCounts[character]++;
            
            if (dictT.find(character) != dictT.end() && 
                windowCounts[character] == dictT[character]) {
                formed++;
            }
            
            // Contract window
            while (left <= right && formed == required) {
                character = s[left];
                
                // Update answer if this window is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                    minRight = right;
                }
                
                windowCounts[character]--;
                if (dictT.find(character) != dictT.end() && 
                    windowCounts[character] < dictT[character]) {
                    formed--;
                }
                
                left++;
            }
            
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
```

#### Problem 3: Maximum Sum Subarray of Size K
**Problem**: Find maximum sum of any subarray of size k
**Approach**: Fixed size sliding window
**Time**: O(n), **Space**: O(1)

```cpp
class Solution {
public:
    int maxSumSubarray(vector<int>& arr, int k) {
        if (arr.size() < k) return -1;
        
        // Calculate sum of first window
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        
        int maxSum = windowSum;
        
        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            windowSum = windowSum - arr[i - k] + arr[i];
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
};
```

### 🧠 Key Insights
- **Efficiency**: Reduces O(n²) or O(n³) to O(n)
- **Memory Optimization**: Often requires only O(1) or O(k) space
- **Versatile**: Works with arrays, strings, and other sequences

---

## 4. Prefix Sum Pattern

### 📖 Overview
Prefix Sum involves pre-computing cumulative sums to answer range sum queries efficiently. It's particularly useful for subarray sum problems.

### 🎯 When to Use
- **Range Sum Queries**: Multiple queries on array ranges
- **Subarray Sum Problems**: Finding subarrays with specific sums
- **2D Matrix**: Row and column sum queries
- **Difference Arrays**: Range update operations

### 🔧 Implementation Types

#### 1. Basic Prefix Sum
```cpp
#include <vector>
using namespace std;

vector<int> buildPrefixSum(vector<int>& arr) {
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    return prefix;
}

int rangeSum(vector<int>& prefix, int left, int right) {
    return prefix[right + 1] - prefix[left];
}
```

#### 2. 2D Prefix Sum
```cpp
vector<vector<int>> build2DPrefix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            prefix[i][j] = matrix[i-1][j-1] + 
                          prefix[i-1][j] + 
                          prefix[i][j-1] - 
                          prefix[i-1][j-1];
        }
    }
    return prefix;
}
```

### 💡 Template Code

```cpp
#include <unordered_map>
#include <vector>
using namespace std;

// Prefix Sum with HashMap Template
int subarraySumProblems(vector<int>& arr, int target) {
    int prefixSum = 0;
    unordered_map<int, int> sumCount;
    sumCount[0] = 1; // Handle subarrays starting from index 0
    int result = 0;
    
    for (int num : arr) {
        prefixSum += num;
        
        // Check if (prefixSum - target) exists
        if (sumCount.find(prefixSum - target) != sumCount.end()) {
            result += sumCount[prefixSum - target];
        }
        
        // Update count of current prefix sum
        sumCount[prefixSum]++;
    }
    
    return result;
}
```

### 📝 Practice Problems

#### Problem 1: Subarray Sum Equals K
**Problem**: Count number of subarrays with sum equal to k
**Approach**: Prefix sum with HashMap
**Time**: O(n), **Space**: O(n)

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        
        for (int num : nums) {
            prefixSum += num;
            
            if (sumCount.find(prefixSum - k) != sumCount.end()) {
                count += sumCount[prefixSum - k];
            }
            
            sumCount[prefixSum]++;
        }
        
        return count;
    }
};
```

#### Problem 2: Range Sum Query - Immutable
**Problem**: Calculate sum of elements between indices i and j
**Approach**: Pre-compute prefix sums
**Time**: O(1) query, O(n) preprocessing, **Space**: O(n)

```cpp
class NumArray {
private:
    vector<int> prefix;
    
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
```

#### Problem 3: Product of Array Except Self
**Problem**: Return array where each element is product of all other elements
**Approach**: Left and right prefix products
**Time**: O(n), **Space**: O(1) excluding output

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Left pass - store left products
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // Right pass - multiply with right products
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return result;
    }
};
```

### 📊 Visual Example
```
Array:     [1, 2, 3, 4, 5]
Prefix:    [0, 1, 3, 6, 10, 15]
           ↑
        Sum from index 0

Range Sum(1, 3) = prefix[4] - prefix[1] = 10 - 1 = 9
Subarray [2, 3, 4] sum = 9 ✓
```

### 🧠 Key Insights
- **Query Efficiency**: O(1) range queries after O(n) preprocessing
- **Space-Time Tradeoff**: Uses extra space for faster queries
- **HashMap Combination**: Powerful for subarray sum problems

---

## 5. Merge Intervals Pattern

### 📖 Overview
The Merge Intervals pattern deals with overlapping intervals, helping to merge, insert, or manipulate interval-based data efficiently.

### 🎯 When to Use
- **Overlapping Intervals**: Merging or finding overlaps
- **Scheduling Problems**: Meeting rooms, calendar conflicts
- **Range Problems**: Coverage, union of ranges
- **Interval Operations**: Insert, remove, intersect intervals

### 🔧 Key Concepts

#### Interval Representation
```cpp
#include <vector>
using namespace std;

// Common representations
vector<int> interval = {start, end};
// or
pair<int, int> interval = {start, end};
// or
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
```

#### Overlap Detection
```cpp
bool overlaps(vector<int>& interval1, vector<int>& interval2) {
    return interval1[1] >= interval2[0] && interval2[1] >= interval1[0];
}

bool canMerge(vector<int>& interval1, vector<int>& interval2) {
    return interval1[1] >= interval2[0]; // Assuming sorted by start
}
```

### 💡 Template Code

```cpp
#include <vector>
#include <algorithm>
using namespace std;

// General Merge Intervals Template
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    // Sort by start time
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        vector<int>& current = intervals[i];
        vector<int>& last = merged.back();
        
        if (current[0] <= last[1]) { // Overlapping
            // Merge intervals
            last[1] = max(last[1], current[1]);
        } else {
            // Non-overlapping
            merged.push_back(current);
        }
    }
    
    return merged;
}
```

### 📝 Practice Problems

#### Problem 1: Merge Intervals
**Problem**: Merge all overlapping intervals
**Approach**: Sort by start time, then merge
**Time**: O(n log n), **Space**: O(1) excluding output

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= merged.back()[1]) {
                // Merge overlapping intervals
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // Add non-overlapping interval
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};

// Example: [[1,3],[2,6],[8,10],[15,18]] → [[1,6],[8,10],[15,18]]
```

#### Problem 2: Insert Interval
**Problem**: Insert new interval and merge if necessary
**Approach**: Three phases - before, merge, after
**Time**: O(n), **Space**: O(1) excluding output

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // Add all intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        result.push_back(newInterval);
        
        // Add remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};
```

#### Problem 3: Meeting Rooms II
**Problem**: Find minimum number of conference rooms needed
**Approach**: Event-based sorting or priority queue
**Time**: O(n log n), **Space**: O(n)

```cpp
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Create events: (time, type) where type: 1=start, -1=end
        vector<pair<int, int>> events;
        for (auto& interval : intervals) {
            events.push_back({interval[0], 1});    // Meeting starts
            events.push_back({interval[1], -1});   // Meeting ends
        }
        
        // Sort events (end events before start events at same time)
        sort(events.begin(), events.end());
        
        int roomsNeeded = 0;
        int maxRooms = 0;
        
        for (auto& event : events) {
            roomsNeeded += event.second;
            maxRooms = max(maxRooms, roomsNeeded);
        }
        
        return maxRooms;
    }
    
    // Alternative: Priority Queue approach
    int minMeetingRoomsPQ(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> heap; // Min heap for end times
        
        for (auto& interval : intervals) {
            // If earliest ending meeting is done, reuse room
            if (!heap.empty() && heap.top() <= interval[0]) {
                heap.pop();
            }
            
            heap.push(interval[1]);
        }
        
        return heap.size();
    }
};
```

#### Problem 4: Non-Overlapping Intervals
**Problem**: Find minimum removals to make intervals non-overlapping
**Approach**: Greedy - keep intervals with earliest end times
**Time**: O(n log n), **Space**: O(1)

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort by end time
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int count = 0;
        int end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                // Overlapping interval, remove it
                count++;
            } else {
                // Non-overlapping, update end time
                end = intervals[i][1];
            }
        }
        
        return count;
    }
};
```

### 🎨 Visual Examples

#### Merge Intervals Example
```
Before: [[1,3], [2,6], [8,10], [15,18]]
        |---|
          |-----|
                 |---|
                       |-----|

After:  [[1,6], [8,10], [15,18]]
        |-------|
                 |---|
                       |-----|
```

#### Meeting Rooms Example
```
Meetings: [[0,30], [5,10], [15,20]]
Timeline: 0    5    10   15   20   30
         |-------|         |-----|         Room 1
              |-----|                      Room 2
                        |-----|            Room 1 (reused)

Maximum rooms needed: 2
```

### 🧠 Key Insights
- **Sorting Strategy**: Usually sort by start time, sometimes by end time
- **Greedy Approach**: Often optimal for interval problems
- **Event-Based Thinking**: Convert intervals to events for complex scenarios
- **Edge Cases**: Empty intervals, single interval, touching intervals

---

## 🎯 Summary and Tips

### Pattern Recognition Guide
| Problem Type | Pattern | Key Indicators |
|--------------|---------|----------------|
| Two elements in sorted array | Two Pointers | "sorted", "two sum", "pairs" |
| Cycle detection | Fast & Slow | "cycle", "duplicate", "linked list" |
| Substring/subarray optimization | Sliding Window | "substring", "subarray", "window" |
| Range queries, subarray sums | Prefix Sum | "range sum", "subarray sum equals" |
| Time intervals, scheduling | Merge Intervals | "intervals", "meetings", "overlapping" |

### General Problem-Solving Approach
1. **Identify the Pattern**: Look for keywords and problem structure
2. **Choose the Right Technique**: Based on constraints and requirements
3. **Consider Edge Cases**: Empty inputs, single elements, boundary conditions
4. **Optimize**: Look for space-time tradeoffs
5. **Test with Examples**: Walk through your solution step by step

### Time Complexity Improvements
- **Brute Force O(n²)** → **Two Pointers O(n)**
- **Nested Loops O(n²)** → **Sliding Window O(n)**
- **Multiple Range Queries O(n×q)** → **Prefix Sum O(n+q)**
- **Interval Processing O(n²)** → **Merge Intervals O(n log n)**

### C++ Specific Tips
- **STL Containers**: Use `vector`, `unordered_map`, `priority_queue` for efficiency
- **Algorithm Library**: Leverage `sort`, `max`, `min` from `<algorithm>`
- **Memory Management**: Prefer references over copies for large data structures
- **Lambda Functions**: Use for custom sorting comparators
- **Auto Keyword**: Simplify iterator declarations

### 🔗 Additional Resources
- Practice these patterns on LeetCode, HackerRank, or CodeChef
- Focus on understanding the underlying principles rather than memorizing solutions
- Time yourself to build speed for interviews
- Study the mathematical proofs behind algorithms like Floyd's cycle detection

Remember: **Consistent practice with these patterns will significantly improve your problem-solving speed and accuracy in coding interviews!**