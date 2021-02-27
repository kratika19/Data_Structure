//TO-do

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

char pop()
{
    char c = stack.Ar[stack.top];
    stack.top--;
    return c;
}

bool checkParenthesis(char *p)
{
    stack.size = strlen(p);
    stack.top = -1;
    stack.Ar = new char [stack.size];
    char ca[stack.size];
    int a = 0;
    for(int i=0;i<stack.size;i++)
        if(p[i] == '(' || p[i] == '{' || p[i] == '[')
            push(p[i]);
        else if(p[i]==')' || p[i]=='}' || p[i]==']') {
            char c = pop();
            if(p[i] == ')')
            {
                if(c == '(')
                    continue;
                else
                {
                    ca[a] = c;
                    a++;
                }
            }
        }
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