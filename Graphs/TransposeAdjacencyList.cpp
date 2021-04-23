#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

int main()
{
    // Construct the Given graph
    int n = 7;
    vector <int> graph[n];
    vector<pair<int,int>> edges = {{0,1},{0,2},{3,2},{3,4},{4,5},{6,5},{6,0}};

    for(auto e : edges)
        addEdge(graph,e.first,e.second);

    // Print Adjacency list of given Graph
    cout<<"The Adjacency List of Given Graph "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto node : graph[i])
            cout<<node<<" ";

        cout<<endl;
    }

    // Obtain transpose of the given graph
    vector <int> transpose[n];
    for(int i=0;i<n;i++)
    {
        for(auto node : graph[i])
            addEdge(transpose,node,i);
    }

    // Print Adjacency list of the Transpose
    cout<<endl<<"The Adjacency List of Transpose Graph "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto node : transpose[i])
            cout<<node<<" ";

        cout<<endl;
    }

    return 0;
}