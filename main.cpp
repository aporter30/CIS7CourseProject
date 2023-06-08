/* 
 * File:   main.cpp
 * Author: Alejandro Porter
 * Created on Apr 25, 2022, 2:41 PM
 * Purpose: Course Project Part 2 - Case 1: Inland Empire Solar Sales Travel
 * 
 * OBJECTIVES
 * 1. If the marketing specialist begins the trip from home in Riverside, 
 *    determine the variations of the trip to the noted cities that he must 
 *    take to market the solar products. COMPLETED
 * 
 * 2. Determine shortest path, and the most low-cost trips for the marketing 
 *    specialist. COMPLETED
 * 
 * 3. Create a C++ program to provide the representation of the trips, 
 *    low-cost and shortest paths, including matrices, adjacencies. COMPLETED
 * 
 * 4. Provide documentation that explains solution and programming approaches.
 * 
 * Vertices: {Riverside(0), Moreno Valley(1), Perris(2), Hemet(3)}
 * Edges:{{1,2},{1,3},{1,4},
 *        {2,1},{2,3},{2,4},
 *        {3,1},{3,2},{3,4},
 *        {4,1},{4,2},{4,3}}
 */

//System Libraries
#include <iostream>
using namespace std;

//Constants
const int NUMNODES = 4;
int minCost = numeric_limits<int>::max();

//Adj Matrix which defines the graph
const int dist[10][10] = {
        {0,24,16,33},
        {24,0,18,30},
        {16,18,0,26},
        {33,30,26,0}
    };

//Vector for optimal paths for Question 2
vector<vector<int> > optimalPaths;

//Function Prototypes
int factorial(int n);
void partOne();
void calculateMinCost(int trip[]);
void printPath(int path[]);
void partTwo();

//Execution starts here
int main() {
    //Question 1
    partOne();
    //Questions 2 and 3
    partTwo();
    //Exit stage right
    return 0;
}
//Function to calculate factorial
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
//Question 1
void partOne(){
    // Calculate the number of remaining nodes
    int remainingNodes = NUMNODES - 1;
    // Calculate the number of variations
    int variations = factorial(remainingNodes);
    //Display results
    cout << "CIS 7 Course Project\n";
    cout << "The total number of variations of the trip "
            "starting from Riverside: " << variations << endl;
    cout<<"(1 = Riverside, 2 = Perris, 3 = Moreno Valley, 4 = Hemet)\n\n";
}
//For Questions 2 and 3 calculate the min cost of all trips
void calculateMinCost(int trip[]) {
    int cost = 0;
    for (int i = 0; i < NUMNODES - 1; ++i) {
        cost += dist[trip[i]][trip[i + 1]];
    }
    cost += dist[trip[NUMNODES - 1]][trip[0]];  // Add the cost to return to the starting node
    if (cost < minCost) {
        minCost = cost;
        optimalPaths.clear();
    }
    if (cost == minCost) {
        vector<int> path(trip, trip + NUMNODES);
        optimalPaths.push_back(path);
    }
    cout << "Cost of trip: " << cost << " for {";
    for (int i = 0; i < NUMNODES; ++i) {
        cout << trip[i] + 1;  // Add 1 to convert back to node numbering starting from 1
        if (i != NUMNODES - 1) {
            cout << " -> ";
        }
    }
    cout << " -> " << trip[0] + 1 << '}'<<endl;  // Print the first node again to complete the path
}
//Function to print optimal trip for questions 2 and 3
void printPath(const vector<int>& path) {
    for (int i = 0; i < NUMNODES; ++i) {
        cout << path[i] + 1;  // Add 1 to convert back to node numbering starting from 1
        if (i != NUMNODES - 1) {
            cout << " -> ";
        }
    }
    cout << " -> " << path[0] + 1 << endl;  // Print the first node again to complete the path
}
//Function to display results
void partTwo(){
    int trip[NUMNODES] = {0, 1, 2, 3};  // Starting with the nodes in their original order

    do {
        calculateMinCost(trip);
    } while (next_permutation(trip + 1, trip + NUMNODES));

    cout << "\nMinimum cost: " << minCost << endl;
    cout << "Optimal paths: " << endl;
    for (const auto& path : optimalPaths) {
        printPath(path);
    }
}
