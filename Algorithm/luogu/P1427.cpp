//
// Created by LuckyE on 2024/4/2.
//
#include "cstdio"
long long a[110];
int n;
int main()
{
	for(int i=0;i<110;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i] == 0)
		{
			break;
		}
		n++;
	}
	while(n--)
	{
		printf("%lld ",a[n]);
	}
	return 0;
}