//
// Created by LuckyE on 2024/4/11.
//
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int l = -2e9,r=2e9;
int main()
{
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		l = max(a/(b+1)+1,l);
		r = min(a/b,r);
	}
	cout<<l<<" "<<r;
	return 0;
}