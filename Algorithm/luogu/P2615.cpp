//
// Created by LuckyE on 2024/4/3.
//
#include "cstdio"
#include "algorithm"

using  namespace  std;

const int N = 3000;
int ans[N][N];
typedef pair<int,int> PII;
int n;
PII st[N];
void p()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d",&n);
	int n2 = n*n;
	st[1] = {1,n/2+1};
	ans[st[1].first][st[1].second] = 1;
	for(int i=2;i<=n2;i++)
	{
		if(st[i-1].first==1&&st[i-1].second!=n)
		{
			st[i] = {n,st[i-1].second+1};
			ans[st[i].first][st[i].second] = i;
//			p();
			continue;
		}

		if(st[i-1].first>1&&st[i-1].second==n)
		{
			st[i] = {st[i-1].first-1,1};
			ans[st[i].first][st[i].second] = i;
//			p();
			continue;
		}

		if(st[i-1].first!=1&&st[i-1].second!=n)
		{
			if(ans[st[i-1].first-1][ st[i-1].second+1] == 0)
			{
				st[i] = {st[i-1].first-1,st[i-1].second+1};
				ans[st[i].first][st[i].second] = i;
			}
			else
			{
				st[i] = {st[i-1].first+1,st[i-1].second};
				ans[st[i].first][st[i].second] = i;
			}
//			p();
			continue;
		}

		if(st[i-1].first==1&&st[i-1].second==n)
		{
			st[i] = {st[i-1].first+1,st[i-1].second};
			ans[st[i].first][st[i].second] = i;
//			p();
			continue;
		}

	}

	p();

	return 0;
}