//
// Created by LuckyE on 2024/4/11.
//
#include <iostream>

#include <algorithm>
using namespace std;
const int N = 1e5+10;

int a[N];
int maxN[N];
int n;

void base(int n)
{
	for(int i=0;i<n;i++)
	{

		for(int j=0;j<n;j++)
		{
			a[j]++;
			maxN[j] = max(a[j],maxN[j]);
		}
		a[i] = 0;
	}
	for(int i=n-2;i>=0;i--)
	{

		for(int j=0;j<n;j++)
		{
			a[j]++;
			maxN[j] = max(a[j],maxN[j]);
		}
		a[i] = 0;
	}
	for(int i=1;i<n;i++)
	{

		for(int j=0;j<n;j++)
		{
			a[j]++;
			maxN[j] = max(a[j],maxN[j]);
		}
		a[i] = 0;
	}
	for(int i=0;i<n;i++)
		cout<<maxN[i]<<endl;
}

// 优化
void generate(int n)
{
	int max = 2*n-2;
	if(n%2)
	{
		for(int i=max ;i>n-2;i-=2)
		{
			cout<<i<<endl;
		}
		for(int i=n+1 ;i<=max;i+=2)
		{
			cout<<i<<endl;
		}
	}
	else
	{
		for(int i=max ;i>n-2;i-=2)
		{
			cout<<i<<endl;
		}
		for(int i=n ;i<=max;i+=2)
		{
			cout<<i<<endl;
		}
	}
}
int main()
{
	cin>>n;
	generate(n);

	return 0;
}