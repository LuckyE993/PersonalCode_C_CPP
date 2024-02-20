//
// Created by LuckyE on 2024/2/20.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1000010;
int st[N];
int path[N];
int n;

void dfs(int x)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
		{
			if(st[i]==1)
			{
				cout<<i<<' ';
			}
		}
		cout<<endl;
		return;
	}

	st[x] = 1;
	dfs(x+1);
	st[x] = 0;

	st[x] = 2;
	dfs(x+1);
	st[x] = 0;
}

int main()
{
	cin>>n;
	dfs(1);
	return 0;
}