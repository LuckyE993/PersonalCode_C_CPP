//
// Created by Lucky_E on 2023-07-21.
//  842. 排列数字
//
#include <iostream>
using namespace std;
#define MAX_NUM 10
int N = MAX_NUM;
int n;
bool state[MAX_NUM+1];
int path[MAX_NUM+1];

void DFS_1(int number)
{
    /*输出*/
    if(number>n)
    {
        for(int i=1; i <= n; i++)
            cout<<path[i]<<" ";
        cout<<endl;
    }

    /*DFS core*/

    for(int i=1; i<=n; i++)
    {
        if(!state[i])
        {
            path[number]=i;
            state[i] = 1;
            DFS_1(number+1);
            state[i] = 0;
        }
    }
}


int main()
{
    cin >> n;
    DFS_1(1);
    return 0;
}