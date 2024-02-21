#include <iostream>
using namespace std;
const int N =1e5+10;
int arr[12];
int n,res;
int ans[60000][12];

void dfs(int x,int sum)
{
	if(sum>n)
		return;
	if(x>10)
	{
		if(sum==n)
		{
			res++;
			for(int i=1;i<=10;i++)
			{
				ans[res][i] = arr[i];
			}
		}
		return;
	}

	for(int i=1;i<=3;i++)
	{
		arr[x] = i;
		dfs(x+1,sum + i);
		arr[x] = 0;
	}
}
int main()
{
	scanf("%d",&n);
	if(n>30||n<10)
	{
		printf("0");
		return 0;
	}

	dfs(1,0);

	printf("%d\n",res);
	for(int i=1;i<=res;i++)
	{
		for(int j=1;j<=10;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}















