//
// Created by LuckyE on 2024/3/24.
//
#include "cstdio"
#include "algorithm"
const int N = 5010;
int n,r;
int answer;
int a[N][N];
int x,y,w;
int main()
{
	scanf("%d %d",&n,&r);
	r = std::min(5001,r);

	while(n--)
	{
		scanf("%d %d %d",&x,&y,&w);
		a[++x][++y] += w;
	}

	for(int i=1;i<=5001;i++)
	{
		for(int j=1;j<=5001;j++)
		{
			a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}

	for(int i=r;i<=5001;i++)
	{
		for(int j=r;j<=5001;j++)
		{
			answer = std::max(answer,a[i][j]-a[i-r][j]-a[i][j-r]+a[i-r][j-r]);
		}
	}

	printf("%d",answer);

	return 0;
}