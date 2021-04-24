#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}*front = NULL, *rear = NULL;

void Enqueue(int x)
{
    Node* t = new Node;
    if(t==NULL)
        cout<<"Full"<<endl;
    else{
        t->data = x;
        t->next = nullptr;

        if(front == NULL)
            front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue()
{
    int x = -1;
    struct Node *p = front;
    if(front== nullptr)
        cout<<"Empty"<<endl;
    else{
        x = p->data;
        front = front ->next;
        delete p;
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}

void BFS(int G[][7], int v, int n)
{
    int visited[7] = {0};
    cout<<v<<" ";
    visited[v] = 1;
    Enqueue(v);

    while(!isEmpty())
    {
        v = Dequeue();
        for(int i = 1;i<n;i++)
        {
            if(G[v][i] == 1 && visited[i] == 0)
            {
                cout<<i<<" ";
                visited[i] = 1;
                Enqueue(i);
            }
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

    BFS(A,2,7);

    return 0;
}