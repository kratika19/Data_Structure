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

    int x;
    int choice;
    while (true) {
        cout << "*******QUEUE MENU*******" << endl;
        cout << "Press 1 to insert a value into queue" << endl;
        cout << "Press 2 to delete a value from queue" << endl;
        cout << "Press 3 to peek any value" << endl;
        cout << "Press 4 to display the elements of stack" << endl;
        cout << "Press 5 to exit" << endl;
        cout << "Make your choice :" << endl;
        cin >> choice;
        if (choice != 5) {
            switch (choice) {
                case 1: {
                    cout << "Enter the value to be pushed :" << endl;
                    cin >> x;
                    push(&st, x);
                    cout << "Value pushed successfully!" << endl;
                    break;
                }
                case 2: {
                    int a = pop(&st);
                    cout << "Value " << a << " popped successfully!" << endl;
                    break;
                }
                case 3: {
                    int pos;
                    cout << "Enter position where you want to peak the value :" << endl;
                    cin >> pos;
                    int val = peek(st, pos);
                    cout << "Value at position " << pos << "in stack is " << val << endl;
                    break;
                }
                case 4: {
                    cout << "Stack contents are:" << endl;
                    display(st);
                    break;
                }
                default: {
                    cout << "Invalid choice entered" << endl;
                    break;
                }

            }
        } else {
            break;
        }
    }
    return 0;
}