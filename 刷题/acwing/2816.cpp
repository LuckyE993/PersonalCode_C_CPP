//
// Created by Lucky_E on 2023-07-17.
//
#include "iostream"
using namespace std;
#define MAX 1000010
int arr1[MAX];
int arr2[MAX];
int main()
{
    int num1,num2;
    cin>>num1>>num2;
    for(int i=0;i<num1;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<num2;i++)
    {
        cin>>arr2[i];
    }

    int i=0;
    for(int j=0;j<num2;j++)
    {
        if(i<num1&&arr1[i]==arr2[j])
        {
            i++;
        }
    }
    if(i==num1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}