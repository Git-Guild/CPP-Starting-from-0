/*
Write a minimal console application that lets a teacher track up to 10 student exam grades, display them, and perform basic calculations like finding the top mark and the class average.

*Specifications*

Implement a single-file C++ program containing a GradeBook class and a straightforward main() function according to these rules:

1. Private Variables

• int scores[10] — A fixed-size array holding a maximum of 10 integer scores.
• int count — An integer that tracks exactly how many scores have been added so far.

2. Public Methods

• Constructor — Sets the starting count to 0.
• bool addScore(int s) — Adds the score s to the next available spot in the array if there is room (count < 10). Returns true if added, or false if the array is full.
• void displayScores() — Runs a simple for loop to print all added scores side by side.
• int getHighestScore() — Loops through the active scores to find and return the largest number.
• double getAverageScore() — Loops through the active scores to sum them up, then divides the sum by count to return the decimal average.
*/
#include <iostream>
using namespace std;

class GradeBook{
    int scores[10];
    int count;
    public:
        GradeBook(){
            count = 0;
        }
        bool addScore(int s){
            if(count < 10){
                scores[count] = s;
                count++;
                return true;
            }
            return false;
        }
        void displayScores(){
            if (count == 0) {
                cout << "No scores recorded yet.";
                return;
            }
            for(int i = 0; i < count; i++){
                cout << "Score " << i+1 << " is:" << scores[i] <<endl;
            }
        }

        int greatestScore(){
            if (count == 0) return 0;

            int max = scores[0];
            for(int i = 1; i < count; i++){
                if(scores[i] > max){
                    max = scores[i];
                }
            }
            return max;
        }
        double averageScore(){
            if (count == 0) return 0.0;

            double sum = 0;
            for(int i = 0; i < count; i++){
                sum += scores[i];
            }
            return sum/count;
        }
};

int main(){
    GradeBook gradeBook;
    int score;
    for (int i = 0; i < 10; i++) {
        cout << "Enter a score (0 to exit): ";
        cin >> score;
        if (score == 0) break;
        else if (score < 0){ 
            cout << "Score must be a positive integer!" << endl;
            i--;
            continue;
        }
        else {
            gradeBook.addScore(score);
        }
    }
    gradeBook.displayScores();
    cout << "The highest score is: " << gradeBook.greatestScore() << endl;
    cout << "The average score is: " << gradeBook.averageScore() << endl;
    return 0;
}