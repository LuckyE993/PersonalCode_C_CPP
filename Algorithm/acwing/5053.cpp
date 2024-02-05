//
// Created by Lucky_E on 2023-07-22.
//
#include <iostream>
using namespace std;
int main()
{
    int count;
    cin>>count;
    while (count--)
    {
        int n;
        cin>>n;
        int Mod = n/3;
        while(Mod--)
        {
            cout<<"abc";
        }
        char c[3]={'a', 'b', 'c'};
        for(int i=0;i<n%3;i++)
        {
            cout<<c[i];
        }
        cout<<endl;
    }
    return 0;
}