#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS
void dfs(int startNode, const vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> s; // Stack to manage nodes
    s.push(startNode); // Start from the given node

    while (!s.empty()) {
        int currentNode = s.top(); // Get the top element
        s.pop();

        // If the current node is not visited, visit it
        if (!visited[currentNode]) {
            cout << currentNode << " "; // Print the current node
            visited[currentNode] = true;
        }

        // Push all unvisited neighbors of the current node onto the stack
        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}

int main() {
    // Number of nodes and edges
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Graph adjacency list
    vector<vector<int>> graph(nodes + 1); // Assuming nodes are 1-based indexed

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph, add both directions
    }

    vector<bool> visited(nodes + 1, false); // Visited array

    cout << "DFS traversal starting from node 1: ";
    dfs(1, graph, visited); // Start DFS from node 1

    return 0;
}
