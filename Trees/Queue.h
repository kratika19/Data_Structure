//
// Created by krati on 28-04-2021.
//

#ifndef LINKED_LISTS_QUEUE_H
#define LINKED_LISTS_QUEUE_H

struct Node{
    Node* lchild;
    Node* rchild;
    int data;
};

struct Queue {
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(Queue *q, int size)
{
    q->size = size;
    q->Q = new Node*[q->size];
    q->front = q->rear = 0;
}

void Enqueue(Queue *q, Node* x) {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
}

Node* Dequeue(Queue *q) {
    Node* x = nullptr;
    if (q->front == q->rear)
        return x;
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
        return x;
    }
}

int isEmpty(Queue q)
{
    return (q.front == q.rear);
}

#endif //LINKED_LISTS_QUEUE_H
