//TODO: Take input from user for a length of string/characters and also for the length of combination, then generate all possible combinations (no two combinations should be same or be palindrome of any other one combination)

/*
Imagine the user enters 12345 as string and 2 as the combination length. The output should be:
12 13 14 15 23 24 25 34 35 45
if the combination length is 3, the output should be:
123 124 125 134 135 145 234 235 245 345 
*/

/*
 ! How I Came Up With This Solution
 * 
 * 1. The Dilemma (Why nested loops aren't enough):
 *    When I wanted combinations of 2 characters (k=2), I naturally thought 
 *    of using two nested loops. But what if the user asks for k=3, k=4, 
 *    or k=10? I can't write 10 nested loops by hand! I needed a way to 
 *    generate loops dynamically based on whatever `k` the user types.

 * 2. The Breakthrough (Recursion as a Multi-Layered Loop):
 *    I realized recursion can act like loops inside loops. Each time the 
 *    function calls itself, it steps one level deeper to pick the next 
 *    character, until our string hits length `k`.

 * 3. Moving Forward (`i + 1`):
 *    To prevent getting duplicates (like "21" when we already have "12") 
 *    or reusing the same letter, I made sure the next choice always starts 
 *    strictly after our current index. Passing `i + 1` ensures we only 
 *    look forward in the string.

 * 4. The Magic of Backtracking (`pop_back()`):
 *    Once we hit length `k` (like "125"), we save it. But how do we get 
 *    back to "12" to try "124"? That's where `pop_back()` comes in! 
 *    It chops off the last character, allowing us to step back, try a 
 *    different option, and keep exploring.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// what do we need for recursion?
/*
1. the actual user string (const string& str) we use const string& because we don't want to change the string in the function but we pass it by reference
2. the length of the combination (k)
3. the current index in the string of loop/recursion, in main we start by 0, in the function we start by the index of the first character by i+1
4. the current string made by recursion
5. the vector to store the combinations
*/
void generateCombinations(const string& str, int k, int start, string current, vector<string>& arr){

    // Base case: If we have the combo to be equal in length to k, we save it
    if(current.length() == k){
        arr.push_back(current);
        return; // this will exit the function
    }

    // we start at 0(start) and go till length of string(str.size())
    for(int i = start; i < str.size(); i++){
        current.push_back(str[i]); // we push the current character to the "current" string, so like "12" and eventually "123" or so
        generateCombinations(str, k, i+1, current, arr); // now say we have "1" or "12" but we need for k=3, so we call the function again with "1" and "12" as the current string
        current.pop_back(); // now this will not be initiated until 123 is saved in arr and we go back to "12" using this line and then it will find other combos like 124 or 125, same happens once we complete the loop (for 1) and it will then go to 2 and find combos like 23 or 24 and so on
    }
}

int main() {

    string str;
    cout << "Enter your characters: ";
    cin >> str;

    int k;
    cout << "Enter combination length (e.g., 2, 3, 4): ";
    cin >> k;
    
    vector<string> arr;

    generateCombinations(str, k, 0, "", arr);

    cout << "Generated pairs: ";
    for (const string& pair : arr) { // loop to print the combinations, you can use any other form of loop, I used this because it was the shortest and I didn't want to complicate with more lines of code
        cout << pair << " ";
    }
    cout << endl;

    return 0;
}
