#include <iostream>

using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} queue;

void insertElement(struct Queue *q, int x) {
    if (q->rear == q->size - 1)
        cout << "Queue overflow!!" << endl;
    else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int deleteElement(struct Queue *q) {
    int a = -1;
    if (q->rear == q->front)
        cout << "Queue underflow!!" << endl;
    else {
        q->front++;
        a = q->Q[q->front];
    }
    return a;
}

void display(struct Queue q) {
    int f = q.front + 1;
    while (f <= q.rear) {
        cout << q.Q[f]<<endl;
        f++;
    }
}

int main() {
    cout << "Enter size of queue :" << endl;
    cin >> queue.size;
    queue.front = queue.rear = -1;
    queue.Q = new int[queue.size];
    insertElement(&queue, 1);
    insertElement(&queue, 1);
    insertElement(&queue, 1);
    insertElement(&queue, 1);
    insertElement(&queue, 1);
    insertElement(&queue, 1);
    display(queue);
    cout << endl;
    deleteElement(&queue);
    display(queue);
    cout << endl;
    return 0;
}