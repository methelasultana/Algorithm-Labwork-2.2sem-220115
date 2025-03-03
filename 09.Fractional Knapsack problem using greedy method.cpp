#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



// Structure to represent an item

struct Item {

    int weight;

    int value;

};



// Comparator function to sort items based on value/weight ratio

bool compare(Item a, Item b) {

    double r1 = (double)a.value / a.weight;

    double r2 = (double)b.value / b.weight;

    return r1 > r2;

}



// Function to solve the Fractional Knapsack Problem

double fractionalKnapsack(int W, vector<Item>& items) {

    sort(items.begin(), items.end(), compare);



    int n = items.size();

    double totalValue = 0.0;



    for (int i = 0; i < n && W > 0; i++) {

        if (items[i].weight <= W) {

            W -= items[i].weight;

            totalValue += items[i].value;

        } else {

            totalValue += items[i].value * ((double)W / items[i].weight);

            W = 0;

        }

    }



    return totalValue;

}



int main() {

    int W = 50; // Knapsack capacity

    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};



    double maxValue = fractionalKnapsack(W, items);

    cout << "Maximum value in Knapsack = " << maxValue << endl;



    return 0;

}