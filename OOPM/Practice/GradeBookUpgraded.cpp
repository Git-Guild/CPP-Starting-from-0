// TODO: Make the best version of GradeBook.cpp you can i.e. check for every sort of exception handling, use cases, better user input(complete mutability in the hands of user without sacrificing memory safety), etc.

#include <iostream>
#include <vector>
using namespace std;

class GradeBook{
    private:
        int size;
        vector<double> scores;
    public:
        GradeBook(int size){
            this->size = size;
        }

        bool addScore(double s){
            if(scores.size() < size){
                scores.push_back(s);
                return true;
            }
            return false;
        }

        void displayScores(){
            if (scores.empty()) {
                cout << "No scores recorded yet.";
                return;
            }
            for(int i = 0; i < scores.size(); i++){
                cout << "Score " << i+1 << " is:" << scores[i] <<endl;
            }
        }

        double greatestScore(){
            if (scores.empty()) return 0;
            double max = scores[0];
            for(int i = 1; i < scores.size(); i++){
                if(scores[i] > max){
                    max = scores[i];
                }
            }
            return max;
        }

        double lowestScore(){
            if (scores.empty()) return 0;
            double min = scores[0];
            for(int i = 1; i < scores.size(); i++){
                if(scores[i] < min){
                    min = scores[i];
                }
            }
            return min;
        }
        
        double averageScore(){
            if (scores.empty()) return 0.0;
            double sum = 0;
            for(int i = 0; i < scores.size(); i++){
                sum += scores[i];
            }
            return sum/scores.size();
        }
};

int main(){
    int size;
    cout << "Enter the number of scores(students) you want to add: ";
    cin >> size;

    GradeBook book(size);
    double score;

    for (int i = 0; i < size; i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        book.addScore(score);
    }

    book.displayScores();
    cout << "The highest score is: " << book.greatestScore() << endl;
    cout << "The lowest score is: " << book.lowestScore() << endl;
    cout << "The average score is: " << book.averageScore() << endl;

    return 0;
}