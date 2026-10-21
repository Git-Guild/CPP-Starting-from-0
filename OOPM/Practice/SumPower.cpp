#include <iostream>
#include <cmath> // for power
#include <vector>

using namespace std;

int sumPower(int n) {
    vector<int> v;
    
    while (n > 0) { // extract digits and store it in a vector array (reverse of the actual number so 123 will be stored as [3, 2, 1])
        int digit = n % 10;
        v.push_back(digit);
        n = n / 10;
    }
    
    int sum = 0;
    for (int i = v.size() - 1; i >= 0; i--) { // start a reverse loop from the last digit to the first digit
        int power = v.size() - i; // power = v.size() - v.size() + 1 = 1 for start but since i decreases this value will increase and therefore, the first digit will get the highest power

        /*
        423 -> [3, 2, 4] = 4 ^ 1 + 2 ^ 2 + 3 ^ 3 = 4 + 4 + 27 = 35
        first iteration: 4 ^ 1 = 4
        second iteration: 2 ^ 2 = 4 (power increased as i decreases)
        third iteration: 3 ^ 3 = 27 (power increased as i decreases)
        */
        sum += pow(v[i], power);
    }
    
    return sum;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    if (n == 0) {
        cout << "Sum of all digits of 0 powered by the index of the digit is: 0" << endl;
        return 0;
    }
    
    n = abs(n);
    
    cout << "Sum of all digits of " << n << " powered by the index of the digit is: " << sumPower(n) << endl;
    return 0;
}
