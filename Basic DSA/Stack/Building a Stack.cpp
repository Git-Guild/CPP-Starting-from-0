#include <iostream>
#include <vector>

using namespace std;

class Stack {
    int size;       // The maximum number of elements the stack can hold
    int top = -1;   // Pointer/Index to track the top element. Starts at -1 because the stack is initially empty.
    vector<int> stack;

    public:
    void setSize() {
        cout << "Enter size of stack: ";
        cin >> size;
        stack.resize(size);
    }

    // Method to add an element to the top of the stack (LIFO)
    void push(int val) {
        // OVERFLOW CHECK: Indexing is 0-indexed, so the final valid slot is at (size - 1).
        // If 'top' is already at the last index, the stack is full.
        if (top == size - 1) { 
            cout << "OVERFLOW! Cannot push " << val << endl; // Block entry to prevent out-of-bounds crash
        } else {
            top++;             // Move the 'top' pointer up to the next available empty slot
            stack[top] = val;  // Store the value at the newly updated 'top' position
            cout << "Pushed " << val << endl;
        }
    }

    // Method to remove the most recently added element from the stack
    void pop() {
        // UNDERFLOW CHECK: If 'top' is still -1, no elements have been successfully pushed.
        if (top == -1) {
            cout << "UNDERFLOW! Stack is empty." << endl; // Block operation as there is nothing to remove
        } else {
            // Read and display the item at the current 'top' before removing it
            cout << "Popped " << stack[top] << endl;
            
            // Move the 'top' pointer down.
            top--; 
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (Top -> Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    
    s.setSize();
    
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(25);
    s.push(19);
    s.push(9);
    
    s.display();
    
    s.pop();
    s.display();
    
    return 0;
}
