#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int edges, vertex;
  
    cout<<"Enter the total number of vertex: ";
    cin>>vertex;

    cout<<"Enter the total number of edges: ";
    cin>>edges;

 
    vector<vector<int>> AdJMatrix(vertex,vector<int>(vertex,0));

    int u , v, weight;

    cout<<"Enter conncetion between vertex and weight:  ";

    for(int i = 0; i < edges; i++)
    {
        cin>> u >> v >> weight;
        AdJMatrix[u][v] = weight;

    }
    
    //Display
    for(int i = 0; i < vertex ; i++)
    {
        for(int j = 0; j < vertex ; j++)
        {
            cout<<AdJMatrix[i][j] <<" ";
        }
        cout<<endl;
    }
   

    return 0;
}