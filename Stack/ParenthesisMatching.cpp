#include <iostream>
#include <cstring>
using namespace std;

struct Stack{
    int size;
    int top;
    char *Ar;
}stack;

void push(char c)
{
    stack.Ar[stack.top] = c;
    stack.top++;
}

void pop()
{
    stack.top--;
}

bool checkParenthesis(char *p)
{
    stack.size = strlen(p);
    stack.top = -1;
    stack.Ar = new char [stack.size];
    for(int i=0;i<stack.size;i++)
        if(p[i] == '(')
            push(p[i]);
        else if(p[i]==')')
            pop();
        else
            continue;

    if(stack.top == -1)
        return true;
    else
        return false;
}
int main()
{
    string eq;
    cout<<"Enter the equation :";
    getline(cin,eq);
    cout<<eq<<endl;
    int l = eq.length() + 1;
    char ch[l];
    strcpy(ch, eq.c_str());
    bool ab = checkParenthesis(ch);
    if(ab)
        cout<<"Parenthesis Matched"<<endl;
    else
        cout<<"Parenthesis not Matched"<<endl;

    return 0;
}