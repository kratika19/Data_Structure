//#include <iostream>
//#include <cstring>
//using namespace std;
//
//struct Stack{
//    int top;
//    int size;
//    char *p;
//} st;
//
//void push(char x)
//{
//    st.p[st.top] = x;
//    st.top++;
//}
//
//char pop()
//{
//    char c = st.p[st.top];
//    st.top--;
//    return c;
//}
//
//char* EvaluatePostfix(char *ch, int l)
//{
//    st.size = l;
//    st.top = -1;
//    st.p = new char[st.size];
//
//    for(int i=0;i<st.size;i++)
//    {
//        if(ch[i] == '+' || ch[i] == '-')
//        {
//
//        }
//    }
//
//}
//
//int main()
//{
//    char *ch = "a+b*c-d/e";
//    int l = strlen(ch);
//    cout<<EvaluatePostfix(ch , l);
//}
