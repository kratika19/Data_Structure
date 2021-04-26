#include <iostream>

using namespace std;

struct Node{
    int dataN;
    Node* nextN;
    Node* prevN;
}*root = NULL;

struct NodeQ{
    int data;
    Node* next;
}*front=nullptr, *rear= nullptr;

void Enqueue(int x)
{
    NodeQ *t = new NodeQ;
    if(t == NULL)
        cout<<"Full";
    else{
        t->data = x;
        t->next = nullptr;

        if(front == nullptr)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue()
{
    NodeQ *p = front;
    int x =-1;
    if(front == nullptr)
        cout<<"Empty";
    else{
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}


int remove(Queue* q)
{
    int x = -1;
    if(q->front == q->rear)
        cout<<"EMPTY";
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void createNode(int n){
    Node *p;
    Node *t;
    Queue q;
    q.front = q.rear = -1;
    q.size = n;
    q.Q = new int[q.size];

    cout<<"Enter node value :";
    int value;
    cin>>value;

    root->data = value;
    root->prev = root->next = nullptr;

    insert(&q, value);

}

int main()
{

}