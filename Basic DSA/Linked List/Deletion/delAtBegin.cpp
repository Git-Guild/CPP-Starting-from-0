#include <iostream>

using namespace std;

struct Node { 
    int data; 
    Node *next; 
    Node(int data) : data(data), next(nullptr) {}
};

// Pass by reference (Node* &head) so the modifications affect the original head pointer
void delAtBegin(Node* &head) { 
    if (head == nullptr) {
        return;
    } 
    Node* temp = head; 
    head = head->next; // Move head to the next node
    delete temp;       // Safely free the memory of the old head
}


int main() {
    Node* head = new Node(1); 
    Node* second = new Node(2); 
    Node* third = new Node(3); 
    
    head->next = second; 
    second->next = third; 
    third->next = nullptr; 
    
    delAtBegin(head); 
    
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
2->3->Null
*/
