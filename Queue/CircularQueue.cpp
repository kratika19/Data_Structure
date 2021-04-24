#include <iostream>

using namespace std;


struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void Enqueue(Queue *q, int x) {
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue is Full!" << endl;
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
        cout << "Element inserted properly" << endl;
    }
}

int Dequeue(Queue *q) {
    int x = -1;
    if (q->front == q->rear)
        cout << "Queue is Empty!" << endl;
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
        cout << x << " deleted properly!" << endl;
    }
    return x;
}

void printQueue(Queue *q) {
    cout << "Elements of Queue are : ";
    int i = q->front +1;
    do{
        cout << q->Q[i] << " ";
        i = (i+1)%q->size;
    }while(i!=(q->rear +1)%q->size);
    cout << endl;
}

int main() {
    struct Queue q;
    cout << "Enter size :";
    cin >> q.size;
    q.Q = new int[q.size];
    q.front = q.rear = 0;
    Enqueue(&q, 5);
    Enqueue(&q, 45);
    Enqueue(&q, 75);
    Enqueue(&q, 25);
    printQueue(&q);
    Dequeue(&q);
    printQueue(&q);
    Enqueue(&q, 75);
    Enqueue(&q, 25);
    printQueue(&q);
    return 0;

}
