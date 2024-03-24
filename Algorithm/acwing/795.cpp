#include "stdio.h"
using namespace std;
const int N = 100010;
int a[N];
int b[N];
int n,m;
int main()
{
	scanf("%d %d ",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]+b[i-1];
	}
	while(m--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",b[r]-b[l-1]);
	}
}

