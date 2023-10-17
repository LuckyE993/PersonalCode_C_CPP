#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
using namespace std;
int stack[10010];
int tt = 0 ;
void push(int value)
{
    stack[tt++] = value;
}
int pop(void)
{
    return stack[tt--];
}
void isempty(void)
{
    if(tt!=0)
        printf("NO\n");
    else
        printf("YES\n");
}
int query(void)
{
    return stack[(--tt)++];
}
int main()
{
    int M,temp;
    cin>>M;
    string s;
    while(M--)
    {
        cin>>s;
        if(s == "push")
        {
            cin>>temp;
            push(temp);
        }
        if(s == "pop")
        {
            pop();
        }
        if(s == "empty")
        {
           isempty();
        }
        if(s == "query")
        {
            cout<<query()<<endl;
        }


    }

    return 0;
}
