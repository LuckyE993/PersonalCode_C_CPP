//
// Created by LuckyE on 2024/3/15.
// 789. 数的范围
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+10;
int n,q;
int a[N];

int main()
{
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	while(q--)
	{
		int temp;
		cin>>temp;
		int l=-1,r = n;
		while(l+1!=r)
		{
			int mid = l+r >> 1;
			if(a[mid]>=temp)
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
		}

		if(a[r]!=temp)
		{
			printf("-1 -1 \n");
		}
		else
		{
			int ll = -1, rr=n;
			while(ll+1 != rr)
			{
				int mid = ll+rr >>1;
				if(a[mid]<=temp)
				{
					ll=mid;
				}
				else
				{
					rr = mid;
				}
			}
			printf("%d %d\n",r,ll);
		}


	}

	return 0;
}