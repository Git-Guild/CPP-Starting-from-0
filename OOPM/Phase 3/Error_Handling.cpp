//TODO: Error_Handling.cpp
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // Gives us access to standard C++ error types like out_of_range
#include <limits>

using namespace std;

// Basic division function throwing a string message
int divide(int a, int b) {
    if (b == 0)
        //* 'throw' is like hitting an emergency eject button. 
        // It stops this function immediately and ships this error message text out to the nearest 'catch' block.
        throw "Division by zero error!"; 
    return a / b;
}

// Custom Exception for Financial / Account Errors (e.g., Error 402 Payment Required)
// ': public exception' means this class inherits from C++'s built-in error blueprint.
class InsufficientFundsException : public exception { 
    double deficit; // Private variable to store how much money is missing
public:
    // Constructor: Takes the missing amount and saves it into our deficit variable
    InsufficientFundsException(double missing_amount) {
        deficit = missing_amount;
    }

    //! Necessary things we will be using this later
    // 'const char*' -> This is just an old-school C-language way of saying "a piece of plain text".
    // 'what()'     -> A standard built-in function name that C++ expects every error class to have.
    // 'const'      -> Promises that running this function won't accidentally change any variables inside the class.
    // 'noexcept'   -> Promises the computer: "Hey, this specific function will never crash or throw an error itself."
    // 'override'   -> Tells the compiler: "I am intentionally replacing the built-in standard what() message with my own custom message."
    const char* what() const noexcept override { 
        return "Error 402: Insufficient funds for transaction!"; 
    }

    // A helper function so the program can ask this error object: "Exactly how much money was missing?"
    // The final 'const' just means reading this value won't modify the class data.
    double getDeficit() const { 
        return deficit; 
    }
};

int main() {
    // 1. Basic try/throw/catch with Division by Zero
    try {
        // The program 'tries' to run these lines in order.
        cout << "10 / 2 = " << divide(10, 2) << endl;
        cout << "10 / 0 = " << divide(10, 0) << endl; // This line triggers the 'throw' eject button inside divide()!
        cout << "This line will never print!" << endl; // Because the code jumped straight out to the catch block.
    }
    // This catches the 'const char*' text thrown by the divide function.
    catch (const char* msg) {
        cout << "[CAUGHT]: " << msg << endl;
    }

    // 2. Custom Error Codes / Exceptions (402, 403, 404)
    try {
        int errorCode = 404; // Simulate a "Page Not Found" web error
        if (errorCode == 404) throw 404; // You can throw plain numbers too!
    }
    // This catch block is explicitly waiting for an integer error code.
    catch (int code) {
        if (code == 404) cout << "[CAUGHT ERROR 404]: Resource not found." << endl;
        if (code == 403) cout << "[CAUGHT ERROR 403]: Access forbidden." << endl;
    }

    // 3. Standard Exception Handling (out_of_range)
    try {
        vector<int> v = {10, 20, 30}; // Array with slots 0, 1, and 2
        cout << v.at(5) << endl; // .at(5) checks boundaries, sees slot 5 doesn't exist, and throws a built-in error!
    }
    // Catching the official standard out_of_range error object by reference (&e)
    catch (const out_of_range& e) {
        // e.what() fetches the built-in explanation text provided by C++
        cout << "[CAUGHT STANDARD EXCEPTION]: " << e.what() << endl;
    }

    // 4. Custom Class Exception (Error 402 simulation)
    try {
        double balance = 100.0;
        double withdrawal = 500.0;
        if (withdrawal > balance) {
            // Creates an instance of our custom error object, calculating the deficit (500 - 100 = 400), and throws it.
            throw InsufficientFundsException(withdrawal - balance);
        }
    }
    // Catching our specific custom error object by reference (&e)
    catch (const InsufficientFundsException& e) {
        // e.what() grabs the string we overrode, and e.getDeficit() reads the saved deficit variable.
        cout << "[CAUGHT CUSTOM EXCEPTION]: " << e.what() << " Short by: $" << e.getDeficit() << endl;
    }

    // 5. Catch-all safety net
    try {
        throw 3.14; // Throwing a decimal/double number. No specific catch block below handles doubles!
    }
    // The three dots (...) mean "catch absolutely anything that wasn't caught by previous blocks".
    // It's a universal safety net so your program doesn't crash completely.
    catch (...) {
        cout << "[CAUGHT (...)]: Unknown exception type handled safely." << endl;
    }

    return 0;
}
