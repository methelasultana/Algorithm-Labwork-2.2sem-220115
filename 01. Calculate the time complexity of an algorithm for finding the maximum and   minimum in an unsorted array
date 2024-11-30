#include <iostream>
using namespace std;

void findMaxMin(int arr[], int n, int &max, int &min) {
    max = arr[0];
    min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
}

int main() {
    int arr[] = {3, 5, 1, 10, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;
    findMaxMin(arr, n, max, min);
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    return 0;
}

