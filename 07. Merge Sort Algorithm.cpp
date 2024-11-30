#include <iostream>
using namespace std;

// Merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2]; // Temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left; // Merging process
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) // Copy remaining elements of L
        arr[k++] = L[i++];
    while (j < n2) // Copy remaining elements of R
        arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);        // Sort first half
        mergeSort(arr, mid + 1, right);  // Sort second half
        merge(arr, left, mid, right);    // Merge the two halves
    }
}

int main() {
int arr[] = {38, 27, 43, 3, 9, 82, 10};
int n = sizeof(arr) / sizeof(arr[0]);
cout << "Original array: ";
for (int i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
mergeSort(arr, 0, n - 1);
cout << "Sorted array: ";
for (int i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
return 0;
}

