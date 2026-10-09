//TODO: Insert a new node at the end of the list

#include <iostream>
using namespace std;

// Node, printList and the cleanup loop are identical to InsertAtFirst.cpp —
// read that file first; only the NEW logic is explained in detail here.
struct Node {
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

void insertAtLast(Node *&head, int data) {
    Node *newNode = new Node(data);
    
    //! Empty-list check: if head is nullptr there is no last node to walk to,
    // so the new node simply becomes the head.
    //* Skipping this check would make the while loop below dereference nullptr
    // and crash — on most systems that's a "segmentation fault" (access violation).
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Walk until temp sits ON the last node (the one whose next is nullptr).
    // Note: the condition checks temp->next, NOT temp — we stop one node early.
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // The old last node now links to the new node; no other node changes
    temp->next = newNode;
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
    Node *head = nullptr;

    // Inserting at the last position KEEPS insertion order (1..5, not reversed)
    insertAtLast(head, 1);
    insertAtLast(head, 2);
    insertAtLast(head, 3);
    insertAtLast(head, 4);
    insertAtLast(head, 5);

    cout << "Linked List: ";
    printList(head);

    // Same heap cleanup as InsertAtFirst.cpp
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
Output:
Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
*/
