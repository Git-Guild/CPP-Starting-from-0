#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

// Pass head by reference (Node*&) or return the updated head pointer
void insertAtPos(Node* &head, int pos, int val) {
    if (pos < 1) { // pos cannot be 0 or negative
        cout << "Position out of bounds!" << endl;
        return;
    }

    if (pos == 1) { // same as insertAtFirst
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *cur = head;
    // Traverse to the node just before the target position (pos - 1 steps from head)
    for (int i = 1; i < pos - 1 && cur != nullptr; i++) {
        cur = cur->next;
    }

    // If cur is nullptr, the requested position is past the end + 1
    if (cur == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    /*
    your list: [10] -> [20] -> [30]
    you want to insert 40 at pos 3
    cur is pointing at 20, cur->next is 30
    */
    Node *newNode = new Node(val);
    /*
    left side is variable, right side is value
    so newNode (40) is now pointing at 30
    cur (20) is now pointing at 40
    so 2 values are now pointing at 30
    */
    newNode->next = cur->next; 
    
    // tell cur to point to newNode i.e. 20 -> 40 (cur was 20, previously cur->next was 30 but now cur->next is 40)
    cur->next = newNode;

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

    insertAtPos(head, 1, 10);  // list: 10 (value=10 at pos=1)
    insertAtPos(head, 2, 20);  // list: 10 -> 20
    insertAtPos(head, 3, 30);  // list: 10 -> 20 -> 30
    insertAtPos(head, 3, 40);  // list: 10 -> 20 -> 40 -> 30
    insertAtPos(head, 5, 50);  // list: 10 -> 20 -> 40 -> 30 -> 50
    insertAtPos(head, 7, 99);  // prints "Position out of bounds!"

    cout << "Linked List: ";
    printList(head);

    return 0;
}

// The values and positions are hardcoded (manual representation) here —
// you can make it dynamic by taking them from the user (cin).

/*
Output:
Position out of bounds!
Linked List: 10 -> 20 -> 40 -> 30 -> 50 -> NULL
*/
