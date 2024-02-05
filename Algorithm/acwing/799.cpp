//
// Created by Lucky_E on 2023-07-17.
//
#include "iostream"
#include "algorithm"
#include "cmath"
#define MAX 1000010
int arr[MAX];
int s[MAX];
int res;
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    for(int i = 0,j = 0; i < n; i++)
    {
       s[arr[i]]++;
       while(s[arr[i]]>1)
       {
           s[arr[j]]--;
           j++;
       }
        res = max(res,i-j+1);
    }
    cout<<res<<endl;

    return 0;
}