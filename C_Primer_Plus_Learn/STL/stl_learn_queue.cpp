//
// Created by Lucky_E on 2023-07-20.
//
#include <iostream>
#include <queue>

using namespace std;
int main()
{
    queue<int> queue1;
    queue<int> queue2;
    queue1.push(10);
    cout<<"queue1 front = "<<queue1.front()<<endl;
    queue1.push(20);
    cout<<"queue1 front = "<<queue1.back()<<endl;
    if(queue1.empty()) {
        cout << "queue1 empty" << endl;
    }
    else
    {
        cout<<"queue1 is not empty"<<endl;
    }
    for(int i=0; i<10;i++)
    {
        queue2.push(i);
    }
    while(!queue2.empty())
    {
        cout<<queue2.front()<<" ";
        queue2.pop();
    }

    return 0;
}