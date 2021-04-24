#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
}*front = nullptr, *rear = nullptr;

void Enqueue(int x)
{
    Node *t = new Node;
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
    Node *p = front;
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

void printQueue()
{
    Node *p = front;
    while(p)
    {
        cout<<p->data<<" ";
        p= p->next;
    }
    cout<<endl;
}

int main()
{
    Enqueue(15);
    Enqueue(16);
    Enqueue(17);
    Enqueue(18);
    Enqueue(19);
    Enqueue(20);
    Enqueue(21);
    printQueue();
    Dequeue();
    Dequeue();
    printQueue();
}