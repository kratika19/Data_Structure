#include <iostream>
using namespace std;

struct Stack{
   int size;
   int top;
   int *Ar;
}st;

void push(Stack *s , int x)
{
    if(s->top == s->size-1)
    {
        cout<<"Stack Overflow !!"<<endl;
    }
    else{
        (s->top)++;
        s->Ar[s->top] = x;
        cout<<"Element added successfully !!"<<endl;
    }
}

int pop(Stack *s)
{
    int x = -1;
    if(s->top == -1)
        cout<<"Stack Underflow !!"<<endl;
    else{
        x = s->Ar[s->top];
        (s->top)--;
        cout<<"Value popped out of stack successfully !!"<<endl;
    }
    return x;
}

int peek(Stack s, int pos)
{
    int index = s.top - pos - 1;
    if(index<0)
        cout<<"Invalid position entered!!"<<endl;
    else
        return s.Ar[index];
}

int stackTop(Stack s)
{
    if(s.top == -1)
        return -1;
    else
        return s.Ar[s.top];
}

bool isEmpty(Stack s)
{
    if(s.top == -1)
        return true;
    else
        return false;
}

bool isFull(Stack s)
{
    if(s.top == s.size-1)
        return true;
    else
        return false;
}

int main()
{
    cout<<"Enter the size of Array :"<<endl;
    cin>>st.size;
    st.Ar = new int[st.size];
    st.top = -1;
}
