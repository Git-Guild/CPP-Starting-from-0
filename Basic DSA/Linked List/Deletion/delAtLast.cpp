#include <iostream>

using namespace std;

struct Node { 
    int data; 
    Node *next; 
    Node(int data) : data(data), next(nullptr) {}
};

void delAtLast(Node* &head) { 
    // Case 1: List is completely empty
    if (head == nullptr) {
        return;
    } 
    
    // Case 2: List has only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    
    // Case 3: List has 2 or more nodes
    Node* temp = head; 
    // Stop at the second-to-last node
    while (temp->next->next != nullptr) { 
        temp = temp->next; 
    } 
    
    // temp->next is the actual last node
    delete temp->next;   // Free the memory of the last node
    temp->next = nullptr; // Disconnect the second-to-last node
}

int main() {
    Node* head = new Node(1); 
    Node* second = new Node(2); 
    Node* third = new Node(3); 
    
    head->next = second; 
    second->next = third; 
    third->next = nullptr; 
    
    delAtLast(head); 
    
    Node* temp = head; 
    while (temp != nullptr) { 
        cout << temp->data << "->"; 
        temp = temp->next; 
    } 
    cout << "Null" << endl; 
    
    return 0;
}

// The nodes are linked manually (hardcoded values) in this file —
// you can make it dynamic by taking the values from the user (cin).

/*
Output:
1->2->Null
*/
