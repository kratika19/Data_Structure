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
        cout << "Value inserted successfully!" << endl;
    }
}

int deleteElement(struct Queue *q) {
    int a = -1;
    if (q->rear == q->front)
        cout << "Queue underflow!!" << endl;
    else {
        q->front++;
        a = q->Q[q->front];
        cout << "Value " << a << " deleted successfully!" << endl;
    }
    return a;
}

void display(struct Queue q) {
    int f = q.front + 1;
    while (f <= q.rear) {
        cout << q.Q[f] << endl;
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
        cout << "Press 3 to display the elements of queue" << endl;
        cout << "Press 4 to exit" << endl;
        cout << "Make your choice :" << endl;
        cin >> choice;
        if (choice != 4) {
            switch (choice) {
                case 1: {
                    cout << "Enter the value to be inserted :" << endl;
                    cin >> x;
                    insertElement(&queue, x);
                    cout << endl;
                    break;
                }
                case 2: {
                    int a = deleteElement(&queue);
                    cout << endl;
                    break;
                }
                case 3: {
                    cout << "Queue contents are:" << endl;
                    display(queue);
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Invalid choice entered" << endl;
                    cout << endl;
                    break;
                }

            }
        } else {
            break;
        }
    }
    return 0;
}