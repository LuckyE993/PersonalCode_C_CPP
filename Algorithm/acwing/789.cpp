//
// Created by LuckyE on 2024/2/16.
//
#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int a[N];
int q,k,n;
int SL(int l,int r ,int x)
{
	while(l<r)
	{
		int mid = l+r >>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}

int SR(int l,int r ,int x)
{
	while(l<r)
	{
		int mid = l+r+1 >>1;
		if(a[mid]<=x) l=mid;
		else r=mid-1;
	}
	return r;

}

int main()
{
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(q--)
	{
		cin>>k;
		int l=SL(0,n-1,k);
		if(a[l]!=k)
			cout<<"-1 -1"<<endl;
		else
		{
			cout<<l<<" "<<SR(0,n-1,k)<<endl;
		}
	}
	return 0;
}