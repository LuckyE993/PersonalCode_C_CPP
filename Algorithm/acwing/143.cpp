//
// Created by LuckyE on 2024/2/5.
//
#include "bits/stdc++.h"
#include <algorithm>
using namespace std;
const int N = 100010;
int son[N*31][2],idx;
int a[N];
void insert(int number)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int u=number>>i & 1;
		if(!son[p][u])
			son[p][u]=++idx;
		p=son[p][u];
	}
}

int find(int number)
{
	int p=0,res=0;
	for(int i=30;i>=0;i--)
	{
		int u=number>>i&1;
		if(son[p][!u])
		{
			p=son[p][!u];
			res=res*2+1;
		}
		else
		{
			p=son[p][u];
			res = res*2;
		}
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int number;
		cin>>a[i];
		insert(a[i]);
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		res = max(res, find(a[i]));
	}
	cout<<res;
}