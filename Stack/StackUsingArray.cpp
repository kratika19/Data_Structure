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

int main()
{
    cout<<"Enter the size of Array :"<<endl;
    cin>>st.size;
    st.Ar = new int[st.size];
    st.top = -1;
}
