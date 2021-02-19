#include <iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
}queue;

int main()
{
    cout<<"Enter size of queue :"<<endl;
    cin>>queue.size;
    queue.front = queue.rear = -1;
    queue.Q = new int[queue.size];

    return 0;
}