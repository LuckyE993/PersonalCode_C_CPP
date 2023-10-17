//
// Created by Lucky_E on 2023-07-22.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n;
void DFS(vector<int>& Stack,vector<bool>& Used,int num)
{
    if(Stack.size() == n)
    {
        for(auto number : Stack)
        {
            cout<<number<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<=num;i++)
    {
        if(!Used[i])
        {
            Used[i] = true;
            Stack.push_back(i);
            DFS(Stack,Used,num);
            Stack.pop_back();
            Used[i] = false;
        }
    }
}

int main()
{

    cin >> n;
    vector<bool> used(n+1,false);
    vector<int> Stack;

    DFS(Stack,used,n);

    return 0;
}