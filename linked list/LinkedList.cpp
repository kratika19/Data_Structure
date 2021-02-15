#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

int count(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void createLL(int A[], int n) {
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    if (p != 0) {
        cout << p->data << endl;
        display(p->next);
    }
}

void insertLL(struct Node *p, int pos, int value) {
    struct Node *t;
    t = new Node;
    t->data = value;
    if (pos == 0) {
        t->next = first;
        first = t;
        cout << "Inserted successfully" << endl;
        display(first);
        cout << endl;
    } else if (pos > 0 && pos < count(p)) {
        p = first;
        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
        cout << "Inserted successfully" << endl;
        display(first);
        cout << endl;
    } else {
        cout << "Invalid position entered" << endl;
    }

}


void deleteNode(struct Node *p, int pos) {
    struct Node *q = NULL;
    string x = "null";
    if (pos >= 1 || pos <= count(p)) {
        if (pos == 1) {
            q = first;
            x = first->data;
            first = first->next;
            delete q;
            cout << "Deleted Successfully" << endl;
            display(first);
            cout<<endl;
        } else if(pos>1 && pos<=count(p)) {
            for (int i = 1; i < pos; i++) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            delete p;
            cout << "Deleted Successfully" << endl;
            display(first);
        }
        else{
            cout<<"Invalid Choice made!!"<<endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements:" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the integer elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    createLL(A, n);
    cout << endl;
    while (true) {
        cout << "Press 1 to insert a new node" << endl;
        cout << "Press 2 to delete an existing node" << endl;
        cout << "Press any number other than 1 or 2 to exit" << endl;
        int choice;
        cout << "Make your choice:";
        cin >> choice;
        cout << endl;
        int pos;
        int value;
        if (choice == 1) {
            cout << "Press 1 to insert a new node at the start" << endl;
            cout << "Press 2 to insert a new node at the end" << endl;
            cout << "Press 3 to insert at a new node at the particular position" << endl;
            int choiceInsert;
            cout << "Make your choice:";
            cin >> choiceInsert;
            int value;

            switch (choiceInsert) {
                case 1: {
                    cout << "Enter the value to be inserted :";
                    cin >> value;
                    cout << endl;
                    insertLL(first, 0, value);
                    cout << endl;
                    break;
                }
                case 2: {
                    cout << "Enter the value to be inserted :";
                    cin >> value;
                    cout << endl;
                    insertLL(first, count(first)-1, value);
                    cout << endl;
                    break;
                }
                case 3: {
                    cout << "Enter the value to be inserted :";
                    cin >> value;
                    cout << "Enter position where you wish to insert the new node:" << endl;
                    cin >> pos;
                    insertLL(first, pos - 2, value);
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Wrong choice made!!" << endl;
                    break;
                }
            }
        } else if (choice == 2) {
            cout << "Press 1 to delete a node at the start" << endl;
            cout << "Press 2 to delete a node at the end" << endl;
            cout << "Press 3 to delete at a node at the particular position" << endl;
            int choiceInsert;
            cout << "Make your choice:";
            cin >> choiceInsert;
            int value;

            switch (choiceInsert) {
                case 1: {
                    deleteNode(first, 1);
                    cout << endl;
                    break;
                }
                case 2: {
                    deleteNode(first, count(first));
                    cout << endl;
                    break;
                }
                case 3: {
                    cout << "Enter position where you wish to delete the node:" << endl;
                    cin >> pos;
                    deleteNode(first, pos);
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Wrong choice made!!" << endl;
                    break;
                }
            }
        } else {
            break;
        }
    }
    return 0;
}