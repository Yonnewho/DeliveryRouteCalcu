#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char buffer) {
    if (n == 1) {
       
        cout << "Move package 1 from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, buffer, destination);

    cout << "Move package " << n << " from " << source << " to " << destination << endl;

    towerOfHanoi(n - 1, buffer, destination, source);
}

int main() {
    int N;
    cout << "Enter the number of packages: ";
    cin >> N;

    towerOfHanoi(N, 'A', 'C', 'B'); 

    cout << "Total number of moves required: " << (1 << N) - 1 << endl; 
    
    return 0;
}

// The process works by breaking the problem into small subproblems. The recursive function continuously breaking the problem down into smaller subproblems until it reaches the base case where N  = 1
// The time complexity of the Tower of Hanoi is O(2n).
