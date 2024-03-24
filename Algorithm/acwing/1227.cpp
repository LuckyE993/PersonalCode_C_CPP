//
// Created by LuckyE on 2024/3/23.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+10;
int w[N],h[N];
int n,k;
bool check(int x)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += (w[i]/x)*(h[i]/x);
		if(sum>=k)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>w[i]>>h[i];
	}

	int l=-1,r = 1e5+10;
	while(l+1!=r)
	{
		int mid = l + (r - l + 1 >> 1);
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}

	}
	printf("%d",l);

	return 0;
}