//
// Created by LuckyE on 2024/4/9.
//
#include <iostream>
#include <cmath>
using namespace std;
const int N = 100010;
#define INF 100000000
int a[N];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		//printf("%d",a[i]);
	}
	int res =0;
	for(int i=0;i<n;i++)
	{
		int MIN = 100000000,MAX = -100000000;
		for(int j=i;j<n;j++)
		{
			MIN = min(a[j],MIN);
			MAX = max(a[j],MAX);
			//printf("%d %d\n",MIN,MAX);
			if(MAX-MIN == j-i)
				res++;
		}
	}
	printf("%d",res);
	return 0;

}