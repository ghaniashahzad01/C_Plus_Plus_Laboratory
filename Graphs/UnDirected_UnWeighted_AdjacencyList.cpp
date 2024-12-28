#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex, edges;

    cout<<"Enter the number of vertex: ";
    cin>>vertex;

    cout<<"Enter the number of edges: ";
    cin>>edges;

    vector<vector<int>>AdJlist(vertex);
    
    cout<<"Enter the connection between vertices:";
    for(int i = 0; i < edges; i++)
    {
    	int u ,  v;
    	cin>> u >> v;
    	
    	AdJlist[u].push_back(v);
    	AdJlist[v].push_back(u);
    	
	}


    cout<<"Adjacency List: \n";
    for(int i = 0 ; i < vertex ; i++)
    {
    	cout<<i<<"->";
    	for(int j = 0; j < AdJlist[i].size(); j++)
    	{
    		cout<<AdJlist[i][j]<<" ";
		}
		
		cout<<endl;
	}


    return 0;
}