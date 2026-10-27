#include <iostream>
#include <stack> // The pre-built stack

using namespace std;

int main() {
    // Create a pre-built stack that holds integers
    // Unlike custom arrays, STL stacks are dynamic and automatically resize!
    stack<int> s;

    // 1. Adding elements using push()
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(25);
    s.push(19);

    // 2. Checking the size of the stack
    cout << "Total elements in stack: " << s.size() << endl;

    // 3. Accessing the top element using top() (equivalent to your peek)
    cout << "Element at the top: " << s.top() << endl;

    // 4. Removing the top element using pop()
    // Note: In C++ STL, pop() removes the element but does NOT return it.
    cout << "Popping the top element..." << endl;
    s.pop(); 

    // Look at the new top after the pop
    cout << "New element at the top: " << s.top() << endl;

    // 5. Checking if the stack is empty and printing remaining elements
    cout << "Remaining elements (Top -> Bottom): ";
    while (!s.empty()) {
        cout << s.top() << " "; // Print the current top element
        s.pop();                // Remove it to move to the next one
    }
    cout << endl;

    // Verify underflow protection
    if (s.empty()) {
        cout << "The stack is now completely empty." << endl;
    }

    return 0;
}
