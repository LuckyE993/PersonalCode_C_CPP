//
// Created by LuckyE on 2024/4/2.
//
#include "cstdio"
#include "algorithm"
using namespace std;
const int N = 2e5+10;
int a[N],st[N];
int sum[N];
int n,ans;
int maxn;
int main()
{
	scanf("%d",&n);
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		st[a[i]] = 1;
	}

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int t = a[i]+a[j];
			if(sum[t] != 0)
				sum[t]++;
			else
				sum[t] = 1;

			maxn = max(maxn,t);
		}

	}

	for(int i=0;i<= maxn;i++)
	{
		if(sum[i] && st[i])
		{
			ans++;
		}
	}

	printf("%d",ans);
	return 0;
}
