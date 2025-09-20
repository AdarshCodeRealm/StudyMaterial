#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }
    
    // Destructor to free memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // 1. INSERT AT BEGINNING - O(1)
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at beginning" << endl;
    }
    
    // 2. INSERT AT END - O(n)
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " at end (first node)" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at end" << endl;
    }
    
    // 3. INSERT AT POSITION - O(n)
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* temp = head;
        
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << endl;
    }
    
    // 4. DELETE BY VALUE - O(n)
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        // If head node contains the value
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << " from beginning" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Value " << value << " not found" << endl;
            return;
        }
        
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Deleted " << value << endl;
    }
    
    // 5. DELETE AT POSITION - O(n)
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node at position 0 with value " << temp->data << endl;
            delete temp;
            return;
        }
        
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted node at position " << position << " with value " << nodeToDelete->data << endl;
        delete nodeToDelete;
    }
    
    // 6. SEARCH - O(n)
    bool search(int value) {
        Node* temp = head;
        int position = 0;
        
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Found " << value << " at position " << position << endl;
                return true;
            }
            temp = temp->next;
            position++;
        }
        
        cout << "Value " << value << " not found in list" << endl;
        return false;
    }
    
    // 7. DISPLAY LIST - O(n)
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
    
    // 8. GET SIZE - O(n)
    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    // 9. REVERSE LIST - O(n)
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
        cout << "List reversed successfully" << endl;
    }
    
    // 10. FIND MIDDLE ELEMENT - O(n)
    int findMiddle() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout << "Middle element: " << slow->data << endl;
        return slow->data;
    }
    
    // 11. DETECT CYCLE - O(n)
    bool hasCycle() {
        if (head == nullptr) return false;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                cout << "Cycle detected in the list" << endl;
                return true;
            }
        }
        
        cout << "No cycle detected" << endl;
        return false;
    }
    
    // 12. GET NTH NODE FROM END - O(n)
    int getNthFromEnd(int n) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        
        Node* first = head;
        Node* second = head;
        
        // Move first pointer n steps ahead
        for (int i = 0; i < n; i++) {
            if (first == nullptr) {
                cout << "List has fewer than " << n << " nodes" << endl;
                return -1;
            }
            first = first->next;
        }
        
        // Move both pointers until first reaches end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        cout << n << "th node from end: " << second->data << endl;
        return second->data;
    }
    
    // 13. REMOVE DUPLICATES (for sorted list) - O(n)
    void removeDuplicates() {
        if (head == nullptr) return;
        
        Node* current = head;
        
        while (current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* nodeToDelete = current->next;
                current->next = current->next->next;
                delete nodeToDelete;
            } else {
                current = current->next;
            }
        }
        
        cout << "Duplicates removed from sorted list" << endl;
    }
    
    // 14. IS EMPTY - O(1)
    bool isEmpty() {
        return head == nullptr;
    }
    
    // 15. CLEAR LIST - O(n)
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "List cleared" << endl;
    }
};

// STL List Operations Class
class STLListOperations {
public:
    list<int> myList;
    
    // 1. INSERT OPERATIONS
    void insertAtBeginning(int value) {
        myList.push_front(value);
        cout << "Inserted " << value << " at beginning using STL" << endl;
    }
    
    void insertAtEnd(int value) {
        myList.push_back(value);
        cout << "Inserted " << value << " at end using STL" << endl;
    }
    
    void insertAtPosition(int value, int position) {
        if (position < 0 || position > myList.size()) {
            cout << "Invalid position" << endl;
            return;
        }
        
        auto it = myList.begin();
        advance(it, position);
        myList.insert(it, value);
        cout << "Inserted " << value << " at position " << position << " using STL" << endl;
    }
    
    // 2. DELETE OPERATIONS
    void deleteByValue(int value) {
        auto it = find(myList.begin(), myList.end(), value);
        if (it != myList.end()) {
            myList.erase(it);
            cout << "Deleted " << value << " using STL" << endl;
        } else {
            cout << "Value " << value << " not found" << endl;
        }
    }
    
    void deleteAtPosition(int position) {
        if (position < 0 || position >= myList.size()) {
            cout << "Invalid position" << endl;
            return;
        }
        
        auto it = myList.begin();
        advance(it, position);
        int value = *it;
        myList.erase(it);
        cout << "Deleted value " << value << " at position " << position << " using STL" << endl;
    }
    
    void deleteFromBeginning() {
        if (!myList.empty()) {
            int value = myList.front();
            myList.pop_front();
            cout << "Deleted " << value << " from beginning using STL" << endl;
        } else {
            cout << "List is empty" << endl;
        }
    }
    
    void deleteFromEnd() {
        if (!myList.empty()) {
            int value = myList.back();
            myList.pop_back();
            cout << "Deleted " << value << " from end using STL" << endl;
        } else {
            cout << "List is empty" << endl;
        }
    }
    
    // 3. SEARCH OPERATIONS
    bool search(int value) {
        auto it = find(myList.begin(), myList.end(), value);
        if (it != myList.end()) {
            int position = distance(myList.begin(), it);
            cout << "Found " << value << " at position " << position << " using STL" << endl;
            return true;
        } else {
            cout << "Value " << value << " not found using STL" << endl;
            return false;
        }
    }
    
    // 4. DISPLAY OPERATIONS
    void display() {
        if (myList.empty()) {
            cout << "STL List is empty" << endl;
            return;
        }
        
        cout << "STL List: ";
        for (auto it = myList.begin(); it != myList.end(); ++it) {
            cout << *it;
            if (next(it) != myList.end()) cout << " <-> ";
        }
        cout << endl;
    }
    
    void displayReverse() {
        if (myList.empty()) {
            cout << "STL List is empty" << endl;
            return;
        }
        
        cout << "STL List (reverse): ";
        for (auto it = myList.rbegin(); it != myList.rend(); ++it) {
            cout << *it;
            if (next(it) != myList.rend()) cout << " <-> ";
        }
        cout << endl;
    }
    
    // 5. UTILITY OPERATIONS
    int getSize() {
        return myList.size();
    }
    
    bool isEmpty() {
        return myList.empty();
    }
    
    void clear() {
        myList.clear();
        cout << "STL List cleared" << endl;
    }
    
    // 6. ADVANCED OPERATIONS
    void reverse() {
        myList.reverse();
        cout << "STL List reversed" << endl;
    }
    
    void sort() {
        myList.sort();
        cout << "STL List sorted" << endl;
    }
    
    void removeDuplicates() {
        myList.sort();  // First sort the list
        myList.unique(); // Remove consecutive duplicates
        cout << "Duplicates removed from STL list" << endl;
    }
    
    int findMiddle() {
        if (myList.empty()) {
            cout << "List is empty" << endl;
            return -1;
        }
        
        auto it = myList.begin();
        advance(it, myList.size() / 2);
        cout << "Middle element: " << *it << endl;
        return *it;
    }
    
    int getNthFromEnd(int n) {
        if (n <= 0 || n > myList.size()) {
            cout << "Invalid position or list too small" << endl;
            return -1;
        }
        
        auto it = myList.end();
        advance(it, -n);
        cout << n << "th element from end: " << *it << endl;
        return *it;
    }
    
    // 7. STL ALGORITHMS
    void merge(STLListOperations& other) {
        myList.sort();
        other.myList.sort();
        myList.merge(other.myList);
        cout << "Lists merged using STL" << endl;
    }
    
    void splice(STLListOperations& other, int position) {
        auto it = myList.begin();
        advance(it, position);
        myList.splice(it, other.myList);
        cout << "List spliced at position " << position << endl;
    }
};

// Forward List Operations (Singly Linked List)
class STLForwardListOperations {
public:
    forward_list<int> fList;
    
    void insertAtBeginning(int value) {
        fList.push_front(value);
        cout << "Inserted " << value << " at beginning of forward list" << endl;
    }
    
    void insertAfter(int afterValue, int newValue) {
        auto it = find(fList.begin(), fList.end(), afterValue);
        if (it != fList.end()) {
            fList.insert_after(it, newValue);
            cout << "Inserted " << newValue << " after " << afterValue << endl;
        } else {
            cout << "Value " << afterValue << " not found" << endl;
        }
    }
    
    void deleteAfter(int afterValue) {
        auto it = find(fList.begin(), fList.end(), afterValue);
        if (it != fList.end() && next(it) != fList.end()) {
            fList.erase_after(it);
            cout << "Deleted element after " << afterValue << endl;
        } else {
            cout << "Cannot delete after " << afterValue << endl;
        }
    }
    
    void deleteFromBeginning() {
        if (!fList.empty()) {
            int value = fList.front();
            fList.pop_front();
            cout << "Deleted " << value << " from beginning of forward list" << endl;
        }
    }
    
    void display() {
        cout << "Forward List: ";
        for (const auto& value : fList) {
            cout << value << " -> ";
        }
        cout << "NULL" << endl;
    }
    
    void reverse() {
        fList.reverse();
        cout << "Forward list reversed" << endl;
    }
    
    void sort() {
        fList.sort();
        cout << "Forward list sorted" << endl;
    }
    
    void removeDuplicates() {
        fList.sort();
        fList.unique();
        cout << "Duplicates removed from forward list" << endl;
    }
};

// Utility functions for demonstration
void printSeparator(const string& title) {
    cout << "\n" << string(60, '=') << endl;
    cout << title << endl;
    cout << string(60, '=') << endl;
}

void demonstrateSTLListOperations() {
    printSeparator("STL LIST (DOUBLY LINKED LIST) OPERATIONS");
    
    STLListOperations stlList;
    
    // Insert operations
    cout << "\n--- Insert Operations ---" << endl;
    stlList.insertAtBeginning(10);
    stlList.insertAtBeginning(5);
    stlList.insertAtEnd(20);
    stlList.insertAtEnd(25);
    stlList.insertAtPosition(15, 2);
    stlList.display();
    // Output: STL List: 5 <-> 10 <-> 15 <-> 20 <-> 25
    
    // Search operations
    cout << "\n--- Search Operations ---" << endl;
    stlList.search(15);
    stlList.search(100);
    
    // Utility operations
    cout << "\n--- Utility Operations ---" << endl;
    cout << "List size: " << stlList.getSize() << endl;
    cout << "Is empty: " << (stlList.isEmpty() ? "Yes" : "No") << endl;
    stlList.findMiddle();
    stlList.getNthFromEnd(2);
    
    // Display operations
    cout << "\n--- Display Operations ---" << endl;
    stlList.display();
    stlList.displayReverse();
    
    // Delete operations
    cout << "\n--- Delete Operations ---" << endl;
    stlList.deleteByValue(10);
    stlList.deleteAtPosition(0);
    stlList.deleteFromEnd();
    stlList.display();
    
    // Advanced operations
    cout << "\n--- Advanced Operations ---" << endl;
    stlList.reverse();
    stlList.display();
    
    // Add some duplicates for testing
    stlList.insertAtEnd(15);
    stlList.insertAtEnd(20);
    stlList.insertAtEnd(15);
    cout << "After adding duplicates:" << endl;
    stlList.display();
    
    stlList.sort();
    stlList.display();
    
    stlList.removeDuplicates();
    stlList.display();
}

void demonstrateSTLForwardList() {
    printSeparator("STL FORWARD LIST (SINGLY LINKED LIST) OPERATIONS");
    
    STLForwardListOperations fList;
    
    cout << "\n--- Insert Operations ---" << endl;
    fList.insertAtBeginning(10);
    fList.insertAtBeginning(5);
    fList.insertAtBeginning(1);
    fList.display();
    // Output: Forward List: 1 -> 5 -> 10 -> NULL
    
    fList.insertAfter(5, 7);
    fList.display();
    // Output: Forward List: 1 -> 5 -> 7 -> 10 -> NULL
    
    cout << "\n--- Delete Operations ---" << endl;
    fList.deleteAfter(5);
    fList.display();
    
    fList.deleteFromBeginning();
    fList.display();
    
    cout << "\n--- Advanced Operations ---" << endl;
    fList.insertAtBeginning(3);
    fList.insertAtBeginning(1);
    fList.insertAtBeginning(8);
    fList.display();
    
    fList.sort();
    fList.display();
    
    fList.reverse();
    fList.display();
}

void demonstrateSTLAlgorithms() {
    printSeparator("STL ALGORITHMS WITH LISTS");
    
    // Using STL algorithms with list
    list<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    cout << "Original list: ";
    for (const auto& num : numbers) cout << num << " ";
    cout << endl;
    
    // Find element
    auto it = find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        cout << "Found 8 at position: " << distance(numbers.begin(), it) << endl;
    }
    
    // Count occurrences
    int count = count_if(numbers.begin(), numbers.end(), [](int n) { return n > 5; });
    cout << "Numbers greater than 5: " << count << endl;
    
    // Transform elements
    list<int> squared;
    transform(numbers.begin(), numbers.end(), back_inserter(squared), 
              [](int n) { return n * n; });
    
    cout << "Squared numbers: ";
    for (const auto& num : squared) cout << num << " ";
    cout << endl;
    
    // Sort and operations
    numbers.sort();
    cout << "Sorted list: ";
    for (const auto& num : numbers) cout << num << " ";
    cout << endl;
    
    // Binary search (requires sorted container)
    bool found = binary_search(numbers.begin(), numbers.end(), 5);
    cout << "Binary search for 5: " << (found ? "Found" : "Not found") << endl;
    
    // Lower and upper bound
    auto lower = lower_bound(numbers.begin(), numbers.end(), 5);
    auto upper = upper_bound(numbers.begin(), numbers.end(), 5);
    cout << "Lower bound of 5: position " << distance(numbers.begin(), lower) << endl;
    cout << "Upper bound of 5: position " << distance(numbers.begin(), upper) << endl;
}

void demonstrateSTLVectorAsList() {
    printSeparator("STL VECTOR AS DYNAMIC ARRAY (Alternative to Linked List)");
    
    vector<int> vec;
    
    // Insert operations
    vec.push_back(10);    // Insert at end
    vec.push_back(20);
    vec.insert(vec.begin(), 5);  // Insert at beginning
    vec.insert(vec.begin() + 2, 15);  // Insert at position
    
    cout << "Vector: ";
    for (const auto& val : vec) cout << val << " ";
    cout << endl;
    // Output: 5 10 15 20
    
    // Access operations
    cout << "First element: " << vec.front() << endl;
    cout << "Last element: " << vec.back() << endl;
    cout << "Element at index 2: " << vec[2] << endl;
    cout << "Element at index 2 (safe): " << vec.at(2) << endl;
    
    // Search operations
    auto it = find(vec.begin(), vec.end(), 15);
    if (it != vec.end()) {
        cout << "Found 15 at position: " << distance(vec.begin(), it) << endl;
    }
    
    // Delete operations
    vec.pop_back();        // Delete from end
    vec.erase(vec.begin()); // Delete from beginning
    vec.erase(vec.begin() + 1); // Delete at position
    
    cout << "After deletions: ";
    for (const auto& val : vec) cout << val << " ";
    cout << endl;
    
    // Utility operations
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "Empty: " << (vec.empty() ? "Yes" : "No") << endl;
    
    // Advanced operations
    vec = {5, 2, 8, 1, 9, 3};
    sort(vec.begin(), vec.end());
    cout << "Sorted vector: ";
    for (const auto& val : vec) cout << val << " ";
    cout << endl;
    
    reverse(vec.begin(), vec.end());
    cout << "Reversed vector: ";
    for (const auto& val : vec) cout << val << " ";
    cout << endl;
}

// ...existing Node and LinkedList code...

int main() {
    cout << "LINKED LIST WITH STL - COMPREHENSIVE GUIDE" << endl;
    cout << string(70, '=') << endl;
    
    // Demonstrate all STL approaches
    demonstrateSTLListOperations();
    demonstrateSTLForwardList();
    demonstrateSTLAlgorithms();
    demonstrateSTLVectorAsList();
    
    printSeparator("STL CONTAINERS COMPARISON");
    cout << "Container          | Type           | Insert/Delete | Random Access | Memory" << endl;
    cout << "-------------------|----------------|---------------|---------------|--------" << endl;
    cout << "std::list          | Doubly Linked  | O(1) at pos   | No O(n)       | Higher" << endl;
    cout << "std::forward_list  | Singly Linked  | O(1) at pos   | No O(n)       | Lower" << endl;
    cout << "std::vector        | Dynamic Array  | O(n) general  | Yes O(1)      | Lower" << endl;
    cout << "std::deque         | Double-ended   | O(1) at ends  | Yes O(1)      | Medium" << endl;
    
    printSeparator("WHEN TO USE WHICH STL CONTAINER");
    cout << "Use std::list when:" << endl;
    cout << "- Frequent insertions/deletions in middle" << endl;
    cout << "- Need bidirectional iteration" << endl;
    cout << "- Memory is not a major concern" << endl;
    cout << endl;
    cout << "Use std::forward_list when:" << endl;
    cout << "- Memory efficiency is crucial" << endl;
    cout << "- Only forward iteration needed" << endl;
    cout << "- Implementing custom data structures" << endl;
    cout << endl;
    cout << "Use std::vector when:" << endl;
    cout << "- Need random access to elements" << endl;
    cout << "- Cache locality is important" << endl;
    cout << "- Mostly appending at end" << endl;
    
    printSeparator("STL QUICK REFERENCE");
    cout << "// STL List Operations:" << endl;
    cout << "list<int> lst;" << endl;
    cout << "lst.push_front(val);     // Insert at beginning" << endl;
    cout << "lst.push_back(val);      // Insert at end" << endl;
    cout << "lst.insert(it, val);     // Insert at iterator position" << endl;
    cout << "lst.pop_front();         // Remove from beginning" << endl;
    cout << "lst.pop_back();          // Remove from end" << endl;
    cout << "lst.erase(it);           // Remove at iterator" << endl;
    cout << "lst.reverse();           // Reverse list" << endl;
    cout << "lst.sort();              // Sort list" << endl;
    cout << "lst.unique();            // Remove consecutive duplicates" << endl;
    cout << "lst.merge(other);        // Merge sorted lists" << endl;
    cout << "lst.splice(it, other);   // Move elements from other list" << endl;
    
    return 0;
}

/* 
EXPECTED OUTPUT:
================
LINKED LIST QUICK REVISION - ALL BASIC OPERATIONS
============================================================

==================================================
1. INSERTION OPERATIONS
==================================================
Inserted 10 at beginning
Inserted 5 at beginning
Inserted 20 at end
Inserted 25 at end
Inserted 15 at position 2
List: 5 -> 10 -> 15 -> 20 -> 25 -> NULL

==================================================
2. SEARCH OPERATIONS
==================================================
Found 15 at position 2
Value 100 not found in list

==================================================
3. SIZE AND UTILITY OPERATIONS
==================================================
List size: 5
Is empty: No
Middle element: 15

==================================================
4. ADVANCED OPERATIONS
==================================================
2nd node from end: 20
No cycle detected

==================================================
5. DELETION OPERATIONS
==================================================
Deleted 10
Deleted node at position 0 with value 5
List: 15 -> 20 -> 25 -> NULL

==================================================
6. REVERSE OPERATION
==================================================
List reversed successfully
List: 25 -> 20 -> 15 -> NULL

==================================================
7. DUPLICATE REMOVAL (DEMO)
==================================================
Before removing duplicates:
List: 1 -> 1 -> 2 -> 3 -> 3 -> 3 -> NULL
Duplicates removed from sorted list
After removing duplicates:
List: 1 -> 2 -> 3 -> NULL
*/