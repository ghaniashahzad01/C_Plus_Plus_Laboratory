#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS on the graph
void BFS(int startNode, vector<vector<int>> &AdjList, int totalNodes) {
    vector<bool> visited(totalNodes, false); // Track visited nodes
    queue<int> q; // Queue for BFS traversal

    visited[startNode] = true; // Mark the start node as visited
    q.push(startNode); // Enqueue the start node

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int current = q.front(); // Get the front node
        q.pop(); // Dequeue it
        cout << current << " "; // Process the node

        // Explore all its neighbors
        for (int i = 0; i < AdjList[current].size(); i++) {
            int neighbor = AdjList[current][i]; // Access neighbor
            if (!visited[neighbor]) { // Check if it’s unvisited
                visited[neighbor] = true; // Mark as visited
                q.push(neighbor); // Enqueue the neighbor
            }
        }
    }
    cout << endl;
}

int main() {
    int totalNodes, edges;

    cout << "Enter the number of nodes in the graph: ";
    cin >> totalNodes;

    if (totalNodes <= 0) {
        cout << "Error: Number of nodes must be greater than zero." << endl;
        return 1; // Exit the program
    }

    cout << "Enter the total number of edges in the graph: ";
    cin >> edges;

    if (edges < 0) {
        cout << "Error: Number of edges cannot be negative." << endl;
        return 1; // Exit the program
    }

    // Adjacency list to store the graph
    vector<vector<int>> AdjList(totalNodes);

    int u, v;
    cout << "Enter the connections between edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        if (u < 0 || u >= totalNodes || v < 0 || v >= totalNodes) {
            cout << "Error: Invalid node index. Nodes must be between 0 and " << totalNodes - 1 << "." << endl;
            return 1; // Exit the program
        }
        AdjList[u].push_back(v); // Add edge u -> v
        AdjList[v].push_back(u); // Add edge v -> u (since it's an undirected graph)
    }

    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;

    if (startNode < 0 || startNode >= totalNodes) {
        cout << "Error: Start node must be between 0 and " << totalNodes - 1 << "." << endl;
        return 1; // Exit the program
    }

    // Perform BFS traversal
    BFS(startNode, AdjList, totalNodes);

    return 0;
}
