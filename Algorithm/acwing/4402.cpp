//
// Created by LuckyE on 2024/4/11.
//
#include <iostream>
using namespace std;
int main()

{
	long long n,a,b;
	long long ans=0;
	cin>>a>>b>>n;
	ans += n/(a*5+b*2)*7;
	n = n%(a*5+b*2);
	if(n)
	{
		for(int i=0;i<5&&n>0;i++)
		{
			n-=a;
			ans++;
		}
		for(int i=0;i<2&&n>0;i++)
		{
			n-=b;
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}