#include <iostream>

using namespace std;

void DFS(int G[][7], int v, int n)
{
    static int visited[7] = {0};
    cout<<v<<" ";
    visited[v] = 1;
    for(int i=1;i<n;i++)
    {
        if(G[v][i] == 1 && visited[i]==0)
        {
            DFS(G,i,n);
        }
    }
}

int main()
{
    int A[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};
    DFS(A,1,7);
    return 0;
}