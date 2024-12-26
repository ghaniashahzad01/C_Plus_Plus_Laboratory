#include<iostream>
using namespace std;
int main()
{
    int vertex, edges;

    cout<<"Enter the number of vertices: ";
    cin>>vertex;

    cout<<"Enter the number of edges: ";
    cin>>edges;

    int AdjMatrix[5][5] = {0};

    int u, v;
  
   //Adjacency Matrix
   cout<<"Enter the connection between edges and enter weight: ";
    for(int i = 0 ; i < vertex; i++)
    {
            cin >> u >> v ;
            AdjMatrix[u][v] = 1;
            AdjMatrix[v][u] = 1;
    }
 
  
  cout<<"Adjacency Matrix: \n";
    for(int i =  0; i < vertex; i++)
    {
        for(int j = 0; j < vertex; j++)
        {
            cout << AdjMatrix[i][j] << " ";
            
        }
        
        cout<<endl;
    }

    return 0;
}
 