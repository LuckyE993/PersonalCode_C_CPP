//
// Created by LuckyE on 2024/3/12.
//
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int N = 5e6+10;

int r[2*N];

int main()
{
	memset(r,-1,sizeof(r));

	int n;
	scanf("%d",&n);

	for(int c=0 ;c*c <= n;c++)
	{
		for(int d = c ;c*c+d*d <= n;d++)
		{
			int t = c*c+d*d;
			if(r[t] == -1)
			{
				r[t] = c;
			}
		}
	}

	for(int a=0 ;a*a <= n;a++)
	{
		for(int b = a ;a*a+b*b <= n;b++)
		{
			int t = n - a*a - b*b;
			int c = r[t];

			if(r[t] == -1)
			{
				continue;
			}
			int d = t- c*c;
			printf("%d %d %d %d",a,b,c,(int)sqrt(d));
			return 0;
		}
	}


	return 0;
}