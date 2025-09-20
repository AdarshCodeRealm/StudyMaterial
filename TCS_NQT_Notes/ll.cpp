#include <bits/stdc++.h>  // Include ALL STL libraries at once
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value) {

        data = value;
        next = nullptr;  // Initialize next pointer to nullptr
    }
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;  // Initialize head to nullptr
    }
    void insert(int value) {
        Node* newNode = new Node(value);
        if(head == nullptr) {
            head = newNode;
        }
        else{
            while(head->next != nullptr) {
                head = head->next;
            }
            head->next = newNode;
        }
       
    }
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool cycleDetection() {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
int main(){
    LinkedList ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    cout << "Linked List created and values inserted." << endl;
    ll.print();  // Assuming a print function exists to display the list
    cout << "Linked List operations completed." << endl;


    vector<int> vec = {1, 2, 3, 4, 5};
    reverse(vec.begin(), vec.end());
    vec.erase(vec.begin() + 2);  // Remove the third element

   for (int i : vec) {
        cout << i << " ";
    }   
    

    return 0;  // Placeholder main function
}