//
// Created by LuckyE on 2024/3/12.
//
#include "bits/stdc++.h"
#include <cstdio>

using namespace std;

const int N = 1e5+10;
int n;
int h[N];
int E;


int main()
{
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}

	for(int i=n;i>=1;i--)
	{
		if((h[i]+E)%2!=0)
		{
			E = (h[i]+E)/2 +1;
		}
		else
		{
			E = (h[i]+E)/2 ;
		}
	}
	printf("%d",E);

}