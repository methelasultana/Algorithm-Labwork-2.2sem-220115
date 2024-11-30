#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
// Linear Search Function
int linearSearch(const vector<string>& names, const string& target) {
for (int i = 0; i < names.size(); i++)
if (names[i] == target) return i;
return -1;
}

// Binary Search Function
int binarySearch(vector<string>& names, const string& target) {
    sort(names.begin(), names.end()); // Ensure the list is sorted for binary search

    int low = 0, high = names.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (names[mid] == target) return mid;
        else if (names[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    vector<string> names = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank",
"Grace", "Hank", "Ivy", "Jack"};
    names.insert(names.end(), 100000, "John"); // Simulate a large dataset
    string target = "Zara";

    // Linear Search
    auto start = chrono::high_resolution_clock::now();
    cout << "Linear Search: " << (linearSearch(names, target) != -1 ? "Found" :
"Not Found") << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(end -
start).count() << " microseconds." << endl;

    // Binary Search
    start = chrono::high_resolution_clock::now();
    cout << "Binary Search: " << (binarySearch(names, target) != -1 ? "Found" :
"Not Found") << endl;
    end = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(end -
start).count() << " microseconds." << endl;

    return 0;
}



