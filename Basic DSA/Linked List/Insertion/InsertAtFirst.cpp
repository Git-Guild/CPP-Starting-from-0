//TODO: Insert a new node at the front of the list

#include <iostream>
using namespace std;

//! struct = a class where everything is public by default — perfect for a simple Node (you can use class as well with some tweaks)
//* A node holds two things: its own value (data) and a link to the next node (next)
struct Node {
    int data;
    Node *next;

    // Member initializer list: members are set the moment the object is created.
    // `next(nullptr)` guarantees a fresh node never points at garbage memory.
    Node(int data) : data(data), next(nullptr) {}
};

//! The head is just a pointer to the first node; nullptr means "empty list"
//* nullptr (Modern C++, since C++11) replaces the old NULL
//* Java/JS use `null` — that does NOT exist in C++, writing it won't compile.

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

// Walks the list node by node until it hits nullptr (end of the list)
void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next; // hop to the next node
    }
    cout << "NULL" << endl; // printed once, after the loop
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

    // `new` allocates on the heap — C++ never frees it for you.
    // Delete every node by hand or the memory is "leaked".
    while (head != nullptr) {
        Node *temp = head;  // remember the node we are about to delete
        head = head->next;  // move head forward FIRST...
        delete temp;        // ...only then delete the old node
    }

    return 0;
}

/*
Output:
Linked List: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
*/
