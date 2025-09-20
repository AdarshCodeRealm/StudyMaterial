#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "STL CONTAINERS - FUNCTION LIST" << endl;
    cout << string(50, '=') << endl;
    
    cout << "\nVECTOR FUNCTIONS:" << endl;
    cout << "==================" << endl;
    cout << "CONSTRUCTORS:" << endl;
    cout << "  vector<int> v;               // Empty vector" << endl;
    cout << "  vector<int> v(5);            // 5 elements with default value" << endl;
    cout << "  vector<int> v(5, 10);        // 5 elements with value 10" << endl;
    cout << "  vector<int> v = {1,2,3};     // Initializer list" << endl;
    cout << "  vector<int> v2(v1);          // Copy constructor" << endl;
    
    cout << "\nCAPACITY:" << endl;
    cout << "  v.size()                     // Number of elements" << endl;
    cout << "  v.capacity()                 // Allocated storage" << endl;
    cout << "  v.max_size()                 // Maximum possible size" << endl;
    cout << "  v.empty()                    // Check if empty" << endl;
    cout << "  v.reserve(n)                 // Reserve capacity" << endl;
    cout << "  v.resize(n)                  // Resize container" << endl;
    cout << "  v.resize(n, val)             // Resize with fill value" << endl;
    cout << "  v.shrink_to_fit()            // Reduce capacity to size" << endl;
    
    cout << "\nELEMENT ACCESS:" << endl;
    cout << "  v[i]                         // Access element (no bounds check)" << endl;
    cout << "  v.at(i)                      // Access element (with bounds check)" << endl;
    cout << "  v.front()                    // First element" << endl;
    cout << "  v.back()                     // Last element" << endl;
    cout << "  v.data()                     // Pointer to first element" << endl;
    
    cout << "\nITERATORS:" << endl;
    cout << "  v.begin()                    // Iterator to beginning" << endl;
    cout << "  v.end()                      // Iterator to end" << endl;
    cout << "  v.rbegin()                   // Reverse iterator to beginning" << endl;
    cout << "  v.rend()                     // Reverse iterator to end" << endl;
    cout << "  v.cbegin()                   // Const iterator to beginning" << endl;
    cout << "  v.cend()                     // Const iterator to end" << endl;
    
    cout << "\nMODIFIERS:" << endl;
    cout << "  v.assign(n, val)             // Assign n elements with value" << endl;
    cout << "  v.assign(first, last)        // Assign from range" << endl;
    cout << "  v.push_back(val)             // Add element at end" << endl;
    cout << "  v.pop_back()                 // Remove last element" << endl;
    cout << "  v.insert(it, val)            // Insert element at position" << endl;
    cout << "  v.insert(it, n, val)         // Insert n copies" << endl;
    cout << "  v.insert(it, first, last)    // Insert range" << endl;
    cout << "  v.erase(it)                  // Erase element at position" << endl;
    cout << "  v.erase(first, last)         // Erase range" << endl;
    cout << "  v.swap(other)                // Swap contents" << endl;
    cout << "  v.clear()                    // Remove all elements" << endl;
    cout << "  v.emplace(it, args...)       // Construct and insert element" << endl;
    cout << "  v.emplace_back(args...)      // Construct and add at end" << endl;
    
    cout << "\n\nQUEUE FUNCTIONS:" << endl;
    cout << "=================" << endl;
    cout << "CONSTRUCTORS:" << endl;
    cout << "  queue<int> q;                // Empty queue" << endl;
    cout << "  queue<int> q2(q1);           // Copy constructor" << endl;
    
    cout << "\nELEMENT ACCESS:" << endl;
    cout << "  q.front()                    // Access first element" << endl;
    cout << "  q.back()                     // Access last element" << endl;
    
    cout << "\nCAPACITY:" << endl;
    cout << "  q.empty()                    // Check if empty" << endl;
    cout << "  q.size()                     // Number of elements" << endl;
    
    cout << "\nMODIFIERS:" << endl;
    cout << "  q.push(val)                  // Add element to back" << endl;
    cout << "  q.pop()                      // Remove front element" << endl;
    cout << "  q.emplace(args...)           // Construct and add element" << endl;
    cout << "  q.swap(other)                // Swap contents" << endl;
    
    cout << "\nPRIORITY QUEUE:" << endl;
    cout << "  priority_queue<int> pq;                              // Max heap" << endl;
    cout << "  priority_queue<int, vector<int>, greater<int>> pq;   // Min heap" << endl;
    cout << "  pq.top()                     // Access top element" << endl;
    cout << "  pq.push(val)                 // Add element" << endl;
    cout << "  pq.pop()                     // Remove top element" << endl;
    cout << "  pq.empty()                   // Check if empty" << endl;
    cout << "  pq.size()                    // Number of elements" << endl;
    
    cout << "\n\nSTACK FUNCTIONS:" << endl;
    cout << "=================" << endl;
    cout << "CONSTRUCTORS:" << endl;
    cout << "  stack<int> s;                // Empty stack" << endl;
    cout << "  stack<int> s2(s1);           // Copy constructor" << endl;
    
    cout << "\nELEMENT ACCESS:" << endl;
    cout << "  s.top()                      // Access top element" << endl;
    
    cout << "\nCAPACITY:" << endl;
    cout << "  s.empty()                    // Check if empty" << endl;
    cout << "  s.size()                     // Number of elements" << endl;
    
    cout << "\nMODIFIERS:" << endl;
    cout << "  s.push(val)                  // Add element to top" << endl;
    cout << "  s.pop()                      // Remove top element" << endl;
    cout << "  s.emplace(args...)           // Construct and add element" << endl;
    cout << "  s.swap(other)                // Swap contents" << endl;
    
    cout << "\n\nTIME COMPLEXITIES:" << endl;
    cout << "==================" << endl;
    cout << "VECTOR:" << endl;
    cout << "  Access: O(1), Insert/Delete at end: O(1) amortized" << endl;
    cout << "  Insert/Delete at middle: O(n), Search: O(n)" << endl;
    
    cout << "\nQUEUE:" << endl;
    cout << "  Push/Pop/Access: O(1), Search: Not supported" << endl;
    
    cout << "\nSTACK:" << endl;
    cout << "  Push/Pop/Access: O(1), Search: Not supported" << endl;
    
    cout << "\n\nCOMMON USAGE PATTERNS:" << endl;
    cout << "======================" << endl;
    cout << "Vector: Dynamic arrays, random access, sorting" << endl;
    cout << "Queue:  BFS, task scheduling, FIFO operations" << endl;
    cout << "Stack:  DFS, expression evaluation, LIFO operations" << endl;
    
    return 0;
}
