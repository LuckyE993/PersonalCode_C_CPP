//
// Created by Lucky_E on 2023-07-18.
//
#include <iostream>
using namespace std;

int num,x;

int main()
{
    cin >> num;
    while(num--)
    {
        int count = 0;
        cin>>x;
        while(x)
        {
            count++;
            x = x&(x-1);
        }
        cout << count << " ";
    }
    return 0;
}