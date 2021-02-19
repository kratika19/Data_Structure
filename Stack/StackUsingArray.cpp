#include <iostream>

using namespace std;

struct Stack {
    int size;
    int top;
    int *Ar;
} st;

void push(Stack *s, int x) {
    if (s->top == s->size - 1) {
        cout << "Stack Overflow !!" << endl;
    } else {
        (s->top)++;
        s->Ar[s->top] = x;
        cout << "Value pushed successfully!" << endl;
    }
}

int pop(Stack *s) {
    int x = -1;
    if (s->top == -1)
        cout << "Stack Underflow !!" << endl;
    else {
        x = s->Ar[s->top];
        (s->top)--;
        cout << "Value " << x << " popped successfully!" << endl;
    }
    return x;
}

int peek(Stack s, int pos) {
    int index = s.top - pos + 1;
    if (index < 0) {
        cout << "Invalid position entered!!" << endl;
        return -1;
    } else
        return s.Ar[index];
}
//
//int stackTop(Stack s) {
//    if (s.top == -1)
//        return -1;
//    else
//        return s.Ar[s.top];
//}
//
//bool isEmpty(Stack s) {
//    if (s.top == -1)
//        return true;
//    else
//        return false;
//}
//
//bool isFull(Stack s) {
//    if (s.top == s.size - 1)
//        return true;
//    else
//        return false;
//}

void display(Stack s) {
    for (int i = s.top; i >= 0; i--)
        cout << s.Ar[i] << endl;
}

int main() {
    cout << "Enter the size of Array :" << endl;
    cin >> st.size;
    st.Ar = new int[st.size];
    st.top = -1;

    int x;
    int choice;
    while (true) {
        cout << "*******STACK MENU*******" << endl;
        cout << "Press 1 to push a value into stack" << endl;
        cout << "Press 2 to pop a value from stack" << endl;
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
                    cout << endl;
                    break;
                }
                case 2: {
                    int a = pop(&st);
                    cout << endl;
                    break;
                }
                case 3: {
                    int pos;
                    cout << "Enter position where you want to peak the value :" << endl;
                    cin >> pos;
                    int val = peek(st, pos);
                    cout << "Value at position " << pos << "in stack is " << val << endl;
                    cout << endl;
                    break;
                }
                case 4: {
                    cout << "Stack contents are:" << endl;
                    display(st);
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
