//
// Created by LuckyE on 2024/4/6.
//
#include <iostream>
#include <cstring>
#include "vector"
using namespace std;
const int N = 2e5+100;
int a[N];

typedef pair<int,int> PII;
PII p[N];
int n;
long long ans;
int cal(int num)
{
	int count = 0;

	while (num)
	{
		if (num & 1)
		{
			count++;
		}
		num = num >> 1;
	}

	if (num < 0)
	{
		count++;
	}
	return count;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	///cout<<cal(3)<<endl;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(g[a[i]][a[j]]!=0)
			{
				ans+= g[a[i]][a[j]];
			}
			else
			{
				g[a[j]][a[i]] = g[a[i]][a[j]] = cal(a[i] & a[j]);

				ans+=g[a[i]][a[j]];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}