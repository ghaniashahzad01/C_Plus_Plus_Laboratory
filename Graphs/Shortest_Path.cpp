#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the shortest path using BFS
void shortestPathBFS(vector<vector<int>>& graph, int source, int destination) {
    int n = graph.size();
    vector<bool> visited(n, false); // To track visited nodes
    vector<int> parent(n, -1);      // To store the path
    queue<int> q;

    // Start BFS from the source node
    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // If we reach the destination, stop BFS
        if (current == destination) break;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current; // Keep track of the path
                q.push(neighbor);
            }
        }
    }

    // Reconstruct the shortest path from source to destination
    vector<int> path;
    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    // Check if there's a valid path
    if (path[0] != source) {
        cout << "No path exists between " << source << " and " << destination << endl;
    } else {
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example graph as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},       // Neighbors of node 0
        {0, 3, 4},    // Neighbors of node 1
        {0, 4},       // Neighbors of node 2
        {1, 5},       // Neighbors of node 3
        {1, 2, 5},    // Neighbors of node 4
        {3, 4}        // Neighbors of node 5
    };

    int source = 0, destination = 5;
    shortestPathBFS(graph, source, destination);

    return 0;
}
