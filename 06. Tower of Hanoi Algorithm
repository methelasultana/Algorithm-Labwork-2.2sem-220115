#include <iostream>
using namespace std;

// Recursive function for Tower of Hanoi
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) { // Base case: one disk
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, target);
    // Move the nth disk to target
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    // Move n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A: Source, C: Target, B: Auxiliary
    return 0;
}


