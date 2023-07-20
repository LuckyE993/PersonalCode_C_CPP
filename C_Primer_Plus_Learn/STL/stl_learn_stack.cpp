//
// Created by Lucky_E on 2023-07-20.
//
#include "iostream"
#include "stack"
using namespace std;
int main()
{
    stack<int> stack1;
    for(int i = 0; i < 10; i++)
    {
        stack1.push(i);
        cout << "The stack top is " << stack1.top()<<endl;
    }
    stack1.pop();
    cout<<"================================================================"<<endl;
    cout << "The stack top is " << stack1.top()<<" after pop"<<endl;
    cout<<"================================================================"<<endl;
    while(!stack1.empty())
    {
        cout << stack1.top()<<" ";
        stack1.pop();
    }

    return 0;
}