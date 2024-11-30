#include <iostream>
#include <climits>
using namespace std;

// Normal Method
void findMinMaxNormal(int arr[], int n, int &min, int &max) {
    min = INT_MAX;
    max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

// Divide and Conquer Method
void findMinMaxDAC(int arr[], int low, int high, int &min, int &max) {
    if (low == high) { // Single element
        min = max = arr[low];
        return;
    }
    if (high == low + 1) { // Two elements
        if (arr[low] < arr[high]) {
            min = arr[low];
            max = arr[high];
        } else {
            min = arr[high];
            max = arr[low];
        }
        return;
    }
    int mid = (low + high) / 2;
    int min1, max1, min2, max2;
    findMinMaxDAC(arr, low, mid, min1, max1);
    findMinMaxDAC(arr, mid + 1, high, min2, max2);
    min = (min1 < min2) ? min1 : min2;
    max = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {3, 1, 5, 9, 2, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    // Normal Method
    findMinMaxNormal(arr, n, min, max);
    cout << "Normal Method - Min: " << min << ", Max: " << max << endl;

    // Divide and Conquer Method
    findMinMaxDAC(arr, 0, n - 1, min, max);
    cout << "Divide and Conquer Method - Min: " << min << ", Max: " << max <<
endl;

    return 0;
}


