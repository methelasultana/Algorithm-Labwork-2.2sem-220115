#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    int choice;
    cout << "Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        bubbleSort(arr, n);
        cout << "Sorted array using Bubble Sort: ";
    } else if (choice == 2) {
        selectionSort(arr, n);
        cout << "Sorted array using Selection Sort: ";
    } else {
        cout << "Invalid choice!";
        return 0;
    }

    printArray(arr, n);
    return 0;
}