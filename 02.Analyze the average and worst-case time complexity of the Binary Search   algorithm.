#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target) {
int low = 0, high = n - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == target)
return mid;
else if (arr[mid] > target)
high = mid - 1;
else
low = mid + 1;
}
return -1;
}
int main() {
int arr[] = {2, 4, 6, 8, 10};
int n = sizeof(arr) / sizeof(arr[0]);
int target = 8;
int result = binarySearch(arr, n, target);
if (result != -1)
cout << "Element found at index: " << result << endl;
else
cout << "Element not found!" << endl;
return 0;
}

