//
//一维差分算法模板
// Created by LuckyE on 2023-06-03.
//

#include "iostream"
using namespace std;

const int N=100100;
int a[N];
int d[N];

int main()
{
    int n,m;
    int l,r,c;

    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        d[i]=a[i]-a[i-1];
    }


    while(m--)
    {
        cin>>l>>r>>c;
        d[l]+=c;
        d[r+1]-=c;
    }

    for(int i=1; i<=n; i++)
    {
        d[i]+=d[i-1];
        cout<<d[i]<<" ";
    }

    return 0;
}
