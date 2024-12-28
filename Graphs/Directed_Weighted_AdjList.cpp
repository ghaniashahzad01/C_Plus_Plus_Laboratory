#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    
    cout << "Enter the number of edges: ";
    cin >> edges;
    
    vector<vector<pair<int,int>>> AdjList(vertices);
    
    cout << "Enter the edges (u v): ";
    for (int i = 0; i < edges; i++) {
        int u, v , weight;
        cin >> u >> v >> weight;
        
        // Add the directed edge from u to v in the adjacency list
        AdjList[u].push_back({v,weight});
    }
    
    // Display the adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << "Neighbour "<<" "<<AdjList[i][j].first << "Weight: "<<" " <<AdjList[i][j].second;
        }
        cout << endl;  // Newline after each vertex's list
    }
    
    return 0;
}
