#include <iostream>
using namespace std;

// Recursive Binary Search using Divide and Conquer
int binarySearchDAC(int arr[], int low, int high, int target) {
    if (low > high) // Base case: element not found
        return -1;

    int mid = low + (high - low) / 2; // Calculate mid to avoid overflow
    if (arr[mid] == target)
        return mid; // Element found
    else if (arr[mid] > target)
        return binarySearchDAC(arr, low, mid - 1, target); // Search left subarray

    else
        return binarySearchDAC(arr, mid + 1, high, target); // Search right subarray

}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearchDAC(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}



