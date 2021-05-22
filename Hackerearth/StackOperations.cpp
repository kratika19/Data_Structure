#include<iostream>
using namespace std;

struct Stack{
    int size;
    int* A;
    int top;
}st;

int pop(Stack* st){
    if(st->top == -1)
        return -1;
    else {
        int x = st->A[st->top];
        st->top--;
        return x; }
}

void push(Stack* st, int num)
{
    st->top++;
    st->A[st->top] = num;
}

int StackOperations(Stack st, int op)
{
    int num = pop(&st);
    op--;
    while(op>0)
    {
        op--;
        if(num>st.A[st.top])
        {
            push(&st, num);
        }
        else
        {
            num = pop(&st);
        }
    }
    if(st.top>-1)
        return st.A[st.top];
    else
        return -1;
}
int main()
{
    int max;
    cin>>st.size>>max;
    st.A = new int[st.size];
    st.top = -1;
    for(int i=0;i<st.size;i++)
    {
        cin>>st.A[st.size - i - 1];
        st.top++;
    }
    int a = StackOperations(st, max);
    cout<<a<<endl;
    return 0;
}

