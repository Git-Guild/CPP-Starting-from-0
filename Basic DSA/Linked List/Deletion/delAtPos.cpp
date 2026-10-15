#include <iostream>

using namespace std;

struct Node { 
    int data; 
    Node *next; 
    Node(int data) : data(data), next(nullptr) {}
};

void delAtPos(Node* &head, int pos) {
    // Edge Case: Invalid position or empty list
    if (head == nullptr || pos <= 0) {
        return;
    } 
    
    // Case 1: Delete the head node (position 1)
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Case 2: Traverse to the node just BEFORE the one we want to delete
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        // If the position is out of bounds, exit safely
        if (temp == nullptr) {
            return;
        }
        temp = temp->next;
    }
    
    // Safety check: Make sure temp and the node to delete (temp->next) actually exist
    if (temp == nullptr || temp->next == nullptr) {
        return;
    }
    
    // Safely untie and delete the node
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

int main() {
    Node* head = new Node(1); 
    Node* second = new Node(2); 
    Node* third = new Node(3); 
    
    head->next = second; 
    second->next = third; 
    third->next = nullptr; 
    
    // Deleting position 2 (the node with value 2)
    delAtPos(head, 2); 
    
    // Print the remaining list
    Node* temp = head; 
    while (temp != nullptr) { 
        cout << temp->data << "->"; 
        temp = temp->next; 
    } 
    cout << "Null" << endl; 
    
    return 0;
}

// The nodes and the position are hardcoded (manual representation) here —
// you can make it dynamic by taking them from the user (cin).

/*
Output:
1->3->Null
*/
