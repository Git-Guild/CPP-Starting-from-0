//TODO: Insert a new node at a position chosen by the user (1-indexed)

#include <iostream>
using namespace std;

// Node, printList and the cleanup loop are identical to InsertAtFirst.cpp —
// read that file first; only the NEW logic is explained in detail here.
struct Node {
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

//! Positions are 1-indexed: 1 = front of the list, len+1 = just past the end
//* Rule: every early return AFTER a `new` must `delete` that node first,
// otherwise the heap memory is leaked — never freed, never reusable.
void insertAtPos(Node *&head, int data, int pos) {
    if (pos < 1) { // 0 and negatives don't exist in 1-indexing
        cout << "Position out of bounds!" << endl;
        return; // nothing allocated yet — nothing to clean up
    }

    Node *newNode = new Node(data);

    // Position 1 is exactly the same two-line insert as insertAtFirst (InsertAtFirst.cpp)
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
/*
    The new node must land AFTER the node at position (pos - 1).
    That previous node is called the "predecessor"
    
    positions:   1      2      3      4      5
    list:      [10] -> [20] -> [30] -> [50] -> NULL
    Insert 40 at pos = 3, so the predecessor is the node at pos 2 ([20]).
    
    !How many steps to reach it?
    * temp starts at pos 1, the target is pos 2, so it walks 2 - 1 = 1 step.
    In general: steps = (pos - 1) - 1 = pos - 2.   (pos - 1 would overshoot!)
*/
    int stepsToPredecessor = pos - 2;
    Node *temp = head;
    for (int i = 0; i < stepsToPredecessor; i++) {
        if (temp == nullptr) { // ran off the end of the list mid-walk
            cout << "Position out of bounds!" << endl;
            delete newNode; // don't leak the node we never linked in
            return;
        }
        temp = temp->next;
    }

    if (temp == nullptr) { // the list ended before we reached the predecessor
        cout << "Position out of bounds!" << endl;
        delete newNode;
        return;
    }

    // Splice: the new node takes over the predecessor's old link
    newNode->next = temp->next;
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

    // Each line: (value to insert, position to insert it at).
    // Values are 10s/50s and positions are 1..7, so the two never look alike.
    insertAtPos(head, 10, 1); // list: 10
    insertAtPos(head, 20, 2); // list: 10 20
    insertAtPos(head, 30, 3); // list: 10 20 30

    // The interesting case: 40 lands at pos 3, pushing 30 to pos 4
    // (walks 3 - 2 = 1 step to [20], then splices 40 between 20 and 30)
    insertAtPos(head, 40, 3); // list: 10 20 40 30

    insertAtPos(head, 50, 5); // list: 10 20 40 30 50   (pos = len + 1 = append)

    // The list has 5 nodes, so the largest valid pos is 6. 7 is past the end.
    insertAtPos(head, 99, 7); // prints "Position out of bounds!"

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
Position out of bounds!
Linked List: 10 -> 20 -> 40 -> 30 -> 50 -> NULL
*/
