//
// Created by LuckyE on 2024/3/27.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+10;
int n,m,ans;


bool dfs(int m,int x,int y)
{
	if(m == 0)
		return true;
	if(m>=x && dfs(m-x,x,y))
		return true;
	if(m>=y && dfs(m-y,x,y))
		return true;

	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=1000;i++)
	{
		if(!dfs(i,n,m))
			ans = i;
	}
	printf("%d",ans);

	return 0;
}