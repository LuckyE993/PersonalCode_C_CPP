//
// Created by Lucky_E on 2023-07-17.
//
#include "iostream"
using namespace std;
#define MAX 1000010
int arr1[MAX];
int arr2[MAX];
int target;

int main()
{
    int num1,num2;
    cin>>num1>>num2>>target;
    for(int i=0;i<num1;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<num2;i++)
    {
        cin>>arr2[i];
    }

    for(int i=0,j=num2-1;i<num1;i++)
    {
        while(j>=0&&arr1[i]+arr2[j]>target)
        {
            j--;
        }
        if(j>=0&&arr1[i]+arr2[j] == target)
        {
            cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}