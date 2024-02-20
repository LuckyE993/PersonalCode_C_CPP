//
// Created by LuckyE on 2024/2/20.
//
#include "iostream"
#include <cstdio>
using namespace std;
const int N=1e5+10;
int st[N];
int arr[30];
int range,n;

void dfs(int x,int start)
{

	if(x>range)
	{
		for(int i=1;i<=range;i++)
		{
			printf("%3d",arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i=start;i<=n;i++)
	{
		arr[x] = i;
		dfs(x+1,i+1);
		arr[x] = 0;
	}
}

int main()
{
	scanf("%d %d",&n,&range);
	dfs(1,1);
	return 0;
}