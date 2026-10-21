//TODO: In Tower of Hanoi, you have 3 rods (source, destination, and helper). You have N disks stacked on source rod from smallest to largest, we need to move this stack to destination rod using another helper rod. The problem is to move the entire stack to destination rod in minimum number of moves.

/*
! RULES:
• Move one disk at a time: You may only transfer a single disk in each turn.
• Top disk only: You can only pick up the topmost (uppermost) disk from any rod.
• No larger on smaller: A larger disk can never be placed on top of a smaller disk.
• Minimum number of moves: 2^n - 1 you moves MUST be equal to this as this is the mathematical answer for this problem.
*/

/*
* Approach:
Printed Step will always be the same: "Move disk N from S to T". The only change will be whether S or T is actually the source or destination rod or are they helper?
N=1: if n=1, then move 1 disk from S to T (S and T are the source and destination rods) [1 move]
N=2: Move 1 disk from S to H, then move 2nd disk from S to T and then disk 1 from H to T [3 moves]
N=3: Basically, now we know how to move if we have 2 disks, so you can move 2 disks from S to H, then move 1 disk from S to T and then move 2 disks from H to T [7 moves]
So we need just these 3 cases to build our algorithm:
Base case: n=1, move 1 disk from S to T
1st recursive case: decrease n by 1, switch places of "helper" and "to" rod variables, print the step
2nd recursive case: decrease n by 1, helper and src switch places (as to initial function arguments), print the step
*/

#include <iostream>
using namespace std;

int stepCount = 0;

void TOH(int n, char src, char to, char help){// remember the order of arguments
    if(n==1){
        stepCount++;
        cout << "Move disk " << n << " from " << src << " to " << to << endl;
        return;
    }
    TOH(n-1, src, help, to); // decrease n by 1, switch places of "helper" and "to" rod variables
    stepCount++;
    cout << "Move disk " << n << " from " << src << " to " << to << endl;

    TOH(n-1, help, to, src); // decrease n by 1, helper and src switch places
}

int main(){
    TOH(3, 'A', 'C', 'B');
    cout << "Total number of moves: " << stepCount << endl;
    return 0;
}