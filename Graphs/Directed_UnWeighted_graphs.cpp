#include<iostream>
using namespace std;

int main()
{
    int edges, vertex;
  
    cout<<"Enter the total number of vertex: ";
    cin>>vertex;

    cout<<"Enter the total number of edges: ";
    cin>>edges;

 
    int AdJMatrix[4][4] = {0};

    int u , v;

    cout<<"Enter conncetion between vertex:  ";

    for(int i = 0; i < edges; i++)
    {
        cin>> u >> v;
        AdJMatrix[u][v] = 1;

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