//
// Created by LuckyE on 2024/2/20.
//
#include <bits/stdc++.h>
#include "cstring"
using namespace std;

#define DFS_Mem false
#define DFS false
#define DP true

const int N =17;
int n;

//Solution begin
int Fibnacci(int x)
{
	if(x==1)
	{
		return 1;
	}
	if(x==2)
	{
		return 1;
	}
	return Fibnacci(x-1)+ Fibnacci(x-2);
}


int mem[N];
int dfs_with_mem(int x)
{
	if(mem[x])
	{
		return mem[x];
	}

	int sum = 0 ;

	if(x==1)
		sum = 1;
	else if(x==2)
		sum = 2;
	else
		sum = dfs_with_mem(x-1)+ dfs_with_mem(x-2);

	mem[x] = sum;
	return sum;
}


int a[N];
int dp(int x)
{
	if(x == 1)
		return 1;
	else if(x == 2)
		return 2;
	else
	{
		a[1] = 1;
		a[2] = 2;
		for(int i=3;i<=x;i++)
		{
			a[i] = a[i-1]+a[i-2];
		}
		return a[x];
	}
}


int main()
{
	cin>>n;
	if(DFS)
		cout << Fibnacci(n);
	if(DFS_Mem)
	{
		memset(mem,0,sizeof mem);
		cout<<dfs_with_mem(n);
	}
	if(DP)
	{
		cout<<dp(n);
	}

	return 0;
}