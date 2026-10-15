//TODO: Learning the Practical approach of linked lists
// please refer to LinkedListBasic.cpp to get a basic idea of what we are advancing on
// we will also not be using this in our explanations but it is good to know and implement it in projects

#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int data) { 
            this->data = data;
            this->next = NULL; 
        }
};
/*
We will make a separate class and add methods in it so we can directly use add and print in main without manually typing out logic in main
*/
class LinkedList {
    public:
        Node* head; //* we initialise node head in the class 
        LinkedList() {
            this->head = NULL; //constructor while making the LinkedList empty
        }
        void add(int data) {
            /*
            ! Logic:
            * if head is null then we add the node to the head
            * else we add the node to the end of the list while the previous one's next point to this new node
            * we use a pointer temp to traverse the list
            */
            Node* newNode = new Node(data);
            if (this->head == NULL) {
                this->head = newNode;
                return;
            }
            Node* temp = this->head;
            while (temp->next != NULL) {
                temp = temp->next; // traverse until the last node
            }
            temp->next = newNode; // add the new node to the end of the list
        }
        void print() {
            Node* temp = this->head;
            while (temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "Null" << endl;
        }
};

int main() {

    LinkedList myLinkedList; //make an object of LinkedList class
    myLinkedList.add(1);
    myLinkedList.add(2);
    myLinkedList.add(3);
    myLinkedList.add(4);
    myLinkedList.add(5);
    myLinkedList.print();
    
    LinkedList myLinkedList1;
    myLinkedList1.add(2);
    myLinkedList1.print();
    
    return 0;
}

// The values added below are hardcoded (manual representation) —
// you can make it dynamic by taking the values from the user (cin).

/*
Output:
1->2->3->4->5->Null
2->Null
*/