#include <iostream>
using namespace std;


struct Queue{
    int size;
    int front;
    int rear;
    int* Q;
};

void Enqueue(Queue* q, int x)
{
    if(q->rear == q->size -1)
        cout<<"Queue is Full!"<<endl;
    else{
        q->rear++;
        q->Q[q->rear] = x;
        cout<<"Element inserted properly"<<endl;
    }
}

int Dequeue(Queue* q)
{
    int x = -1;
    if(q->front == q->rear)
        cout<<"Queue is Empty!"<<endl;
    else
    {
        q->front++;
        x = q->Q[q->front];
        cout<<x<<" deleted properly!"<<endl;
    }
    return x;
}

void printQueue(Queue* q)
{
    cout<<"Elements of Queue are : ";
    for(int i=(q->front)+1;i<=q->rear;i++)
        cout<<q->Q[i]<< " ";
    cout<<endl;
}

int main()
{
    struct Queue q;
    cout<<"Enter size :";
    cin>>q.size;
    q.Q = new int[q.size];
    q.front = q.rear = -1;
    Enqueue(&q, 5);
    Enqueue(&q, 45);
    Enqueue(&q, 75);
    Enqueue(&q, 25);
    printQueue(&q);
    Dequeue(&q);
    printQueue(&q);
    return 0;

}