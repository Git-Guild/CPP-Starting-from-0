//TODO: Find sum of all digits of a number

//Approach 1: take remainder of n by 10 and then add that to a sum variable. Check if sum is 2 digit long, send it back. Retrun sum

#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    int sum=0;
    while(n>0){
        sum += n%10;
        n /= 10;
    }
    if(sum>9) return sumOfDigits(sum);
    return sum;
}
//Approach 2: if n is divisible by 9 then return 9. Else return remainder of n by 9 because mathematically sum of digits of a number is equal to remainder of n by 9.
int sumOfDigitsR(int n) {
    if (n == 0) return 0;
    
    int remainder = n % 9;
    return (remainder == 0) ? 9 : remainder;
}

int main(){
    cout << "Two loop way:" << sumOfDigits(12345) << endl;
    cout << "Remainder by 9 way: " << sumOfDigitsR(12345);
    return 0;
}

