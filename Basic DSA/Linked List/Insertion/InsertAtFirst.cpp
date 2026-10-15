//TODO: Insert a new node at the front of the list

#include <iostream>
using namespace std;

//! struct = a class where everything is public by default — perfect for a simple Node (you can use class as well with some tweaks)
struct Node {
    int data;
    Node *next;

    // Member initializer list: members are set the moment the object is created.
    // `next(nullptr)` guarantees a fresh node never points at garbage memory.
    Node(int data) : data(data), next(nullptr) {}
};


/* 
Node *&head is a REFERENCE to the head pointer, not a copy of it.
Without the &, main() would hand over a copy of the pointer; 
updating the copy inside this function would NOT move the head back in main(). 
*/
void insertAtFirst(Node *&head, int data) {
    Node *newNode = new Node(data); // allocate a node on the heap (new returns a pointer)
    newNode->next = head;           // new node links to the old first node
    head = newNode;                 // head now points at the new node
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *head = nullptr; // start with an empty list

    // Each call puts the new number in FRONT, so the list comes out reversed
    insertAtFirst(head, 1);
    insertAtFirst(head, 2);
    insertAtFirst(head, 3);
    insertAtFirst(head, 4);
    insertAtFirst(head, 5);

    cout << "Linked List: ";
    printList(head);

    return 0;
}

// The values passed to insertAtFirst are hardcoded (manual representation) —
// you can make it dynamic by taking them from the user (cin).

/*
Output:
Linked List: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
*/
