//
// Created by LuckyE on 2024/3/28.
//
#include "bits/stdc++.h"
const int N = 110;
using namespace std;
int a[N];
int n;
int l,r;
int cmp(int x,int y)
{
	return abs(x) < abs(y);
}

int main()
{
	scanf("%d",&n);

	scanf("%d",&a[0]);

	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>0 && abs(a[i])<abs(a[0]))
			l++;
		if(a[i]<0 && abs(a[i])>abs(a[0]))
			r++;

	}

	if((l==0&& a[0]<0) || (r==0&&a[0]>0))
		printf("%d",1);
	else
		printf("%d",l+r+1);
//	sort(a,a+n-1,cmp);
//	for(int i=0;i<n;i++)
//	{
//		printf("%d ",a[i]);
//	}


	return 0;
}