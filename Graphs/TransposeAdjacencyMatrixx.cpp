#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Define The Adjacency Matrix
    vector<vector<int>> graph = {{0,1,1,0,0,0,0},
                                 {0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0},
                                 {0,0,1,0,1,0,0},
                                 {0,0,0,0,0,1,0},
                                 {0,0,0,0,0,0,0},
                                 {1,0,0,0,0,1,0}};

    cout<<"Adjacency Matrix of Given Graph."<<endl;

    for(auto node : graph)
    {
        cout<<"\t";
        for(auto neighbor : node)
            cout<<neighbor<<" ";

        cout<<endl;
    }

    // Perform Matrix Transpose
    for(int i=0;i<graph.size();i++)
    {
        for(int j=i+1;j<graph[0].size();j++)
            swap(graph[i][j],graph[j][i]);
    }

    // Print the Matrix Transpose
    cout<<"\nAdjacency Matrix of Transpose Graph."<<endl;
    for(auto node : graph)
    {
        cout<<"\t";
        for(auto neighbor : node)
            cout<<neighbor<<" ";

        cout<<endl;
    }

    return 0;
}