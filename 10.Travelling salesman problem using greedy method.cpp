#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std; 
 
// Function to calculate distance between two points 
double distance(pair<int, int> a, pair<int, int> b) { 
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); 
} 
 
// Function to find the nearest neighbor 
int nearestNeighbor(int current, const vector<pair<int, int>>& cities, 
vector<bool>& visited) { 
    int n = cities.size(); 
    int nearest = -1; 
    double minDist = numeric_limits<double>::max(); 
 
    for (int i = 0; i < n; i++) { 
        if (!visited[i] && i != current) { 
            double dist = distance(cities[current], cities[i]); 
            if (dist < minDist) { 
                minDist = dist; 
                nearest = i; 
            } 
        } 
    } 
 
    return nearest; 
} 
 
// Function to solve TSP using Greedy Method 
vector<int> tspGreedy(const vector<pair<int, int>>& cities) { 
    int n = cities.size(); 
    vector<int> tour; 
    vector<bool> visited(n, false); 
 
    int current = 0; 
    visited[current] = true; 
    tour.push_back(current); 
 
    for (int i = 1; i < n; i++) { 
        int next = nearestNeighbor(current, cities, visited); 
        visited[next] = true; 
        tour.push_back(next); 
        current = next; 
    } 
 
    tour.push_back(tour[0]); // Return to the starting city 
    return tour; 
} 
 
int main() { 
    vector<pair<int, int>> cities = {{0, 0}, {1, 2}, {4, 3}, {6, 1}, {3, 5}}; 
    vector<int> tour = tspGreedy(cities); 
 
    cout << "Tour: "; 
    for (int city : tour) { 
        cout << city << " "; 
    } 
    cout << endl; 
 
    return 0; 
}