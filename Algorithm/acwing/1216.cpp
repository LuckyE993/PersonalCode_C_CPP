#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ans = 0;
	int n;

	scanf("%d",&n);
	int temp = n;
	while(n>=3)
	{
		n-=2;
		ans++;
	}
	printf("%d",ans+temp);
	return 0;
}