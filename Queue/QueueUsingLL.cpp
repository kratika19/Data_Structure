#include <iostream>

using namespace std;

//struct Queue {
//    int size;
//    int front;
//    int rear;
//    int *Q;
//} queue;

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void insertElement(int x) {
    struct Node *q;
    q = new Node;
    if (q == NULL)
        cout << "Queue overflow!!" << endl;
    else {
        q->data = x;
        q->next = NULL;
        if (front == NULL) {
            front = rear = q;
        } else {
            rear->next = q;
            rear = q;
        }
        cout << "Value inserted successfully!" << endl;
    }
}

int deleteElement() {
    int a = -1;
    struct Node *q;
    if (front == NULL)
        cout << "Queue underflow!!" << endl;
    else {
        a = front->data;
        q = front;
        front = front->next;
        delete q;
        cout << "Value " << a << " deleted successfully!" << endl;
    }
    return a;
}

void display() {
    struct Node *q = front;
    while (q) {
        cout << q->data << endl;
        q = q->next;
    }
}

int main() {
//    cout << "Enter size of queue :" << endl;
//    cin >> queue.size;
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
                    insertElement(x);
                    cout << endl;
                    break;
                }
                case 2: {
                    deleteElement();
                    cout << endl;
                    break;
                }
                case 3: {
                    cout << "Queue contents are:" << endl;
                    display();
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