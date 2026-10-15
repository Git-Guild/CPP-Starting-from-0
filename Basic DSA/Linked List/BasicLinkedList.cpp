//TODO: Learning the basics of linked list

#include <iostream>
using namespace std;

//* A node holds two things: its own value (data) and a link to the next node (next)
class Node { // you can use struct as well
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data; // start as only one node in the list
            this->next = nullptr; // you can use NULL as well but it is not recommended due to its integer nature of being 0 and not a pointer
        }
};

int main() {
    //! Manual way to link and add nodes
    //* we can use another class to make this easy for us but I suggest using this in exams and interviews to save time
    // for a better practical approach check out LinkedList.cpp

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second; // we link the head to the second and so on to link the individual nodes
    second->next = third;
    third->next = nullptr;

    Node* temp = head; 
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next; // hop to the next node
    }
    cout << "Null" << endl; // printed once, after the loop

    //* OPTIONAL: delete temp for memory consumption, will not be used again in this tutorial to keep it simple
    // `new` allocates on the heap — C++ never frees it for you.
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

// The nodes are created and linked manually (hardcoded values) in this file —
// you can make it dynamic by taking the values from the user (cin).

/*
Output:
1->2->3->Null
*/