#include <iostream>

using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;          // base case: stop calling
    return n * factorial(n - 1);   // smaller problem: n - 1
}

int main() {
    int n;
    cout << "Enter a number for factorial: ";
    cin >> n;
    
    cout << "The factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}