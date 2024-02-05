//
// Created by LuckyE on 2024/1/26.
//
#include "bits/stdc++.h"
using namespace std;
const int N=1e5+10;
int tmp[N],q[N];
void MergeSort(int a[],int l,int r)
{
	if(l>=r)
	{
		return;
	}
	int mid = (l+r)>>1;
	MergeSort(a,l,mid);
	MergeSort(a,mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])
		{
			tmp[k++]=a[i++];
		}
		else
		{
			tmp[k++]=a[j++];
		}
	}
	while(i<=mid)
		tmp[k++]=a[i++];
	while(j<=r)
	{
		tmp[k++]=a[j++];
	}
	for (i = l, j = 0; i <= r; i ++, j ++ )
	{
		a[i] = tmp[j];
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>q[i];
	}
	MergeSort(q,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<q[i]<<" ";
	}
	return 0;
}