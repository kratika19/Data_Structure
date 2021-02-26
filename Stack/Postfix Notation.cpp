#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct Stack {
    unsigned size;
    int top;
    int *Ar;
} st;

void push(Stack *s, int x) {
    (s->top)++;
    s->Ar[s->top] = x;
}

int pop(Stack *s) {
    int x = -1;
    x = s->Ar[s->top];
    (s->top)--;
    return x;
}

int stackTop(Stack s) {
    if (s.top == -1)
        return -1;
    else
        return s.Ar[s.top];
}

int solvePostFix(char *p, int l) {
    for (int i = 0; i < l; i++) {
        if (p[i] == ' ')
            continue;
        else if (isdigit(p[i])) {
            push(&st, (p[i] - '0'));
        } else
            switch (p[i]) {
                case '+': {
                    int l = pop(&st);
                    int m = pop(&st);
                    int sum = m + l;
                    push(&st, sum);
                    break;
                }
                case '-' : {
                    int l = pop(&st);
                    int m = pop(&st);
                    int diff = m - l;
                    push(&st, diff);
                    break;
                }
                case '*' : {
                    int l = pop(&st);
                    int m = pop(&st);
                    int pro = m * l;
                    push(&st, pro);
                    break;
                }
                case '/' : {
                    int l = pop(&st);
                    int m = pop(&st);
                    int div = m / l;
                    push(&st, div);
                    break;
                }
                case '^' : {
                    int l = pop(&st);
                    int m = pop(&st);
                    int exp = floor(pow(m , l));
                    push(&st, exp);
                    break;
                }

            }
    }
    int result = stackTop(st);
    return result;
}

int main() {
    string str;
    cout << "Enter the expression :";
    getline(cin, str);

    int size = str.length() + 1;
    st.size = size;
    st.Ar = new int[st.size];
    st.top = -1;

    char ch[size];
    strcpy(ch, str.c_str());
    cout << "Postfix Evaluation yields :" << solvePostFix(ch, size);
    return 0;
}
