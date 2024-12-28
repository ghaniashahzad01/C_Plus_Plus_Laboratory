#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    
    cout << "Enter the number of edges: ";
    cin >> edges;
    
    vector<vector<pair<int, int>>> AdjList(vertices);
    
    cout << "Enter the edges (u, v, weight): \n";
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        
        AdjList[u].push_back({v, weight});
        AdjList[v].push_back({u, weight});
    }
    
    cout << "Adjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << "(Neighbor: " << AdjList[i][j].first << ", Weight: " << AdjList[i][j].second << ") ";
        }
        cout << endl;
    }
    
    return 0;
}
