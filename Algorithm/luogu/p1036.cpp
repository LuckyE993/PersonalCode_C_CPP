//
// Created by LuckyE on 2024/2/20.
//
#include "iostream"
#include "cmath"
using namespace std;

const int N=1e5+10;
int arr[N],q[N];
int n,k;
int res;

bool is_prim(int sum)
{
	if(sum<2)
		return false;
	for(int i=2;i<= sqrt(sum);i++)
	{
		if(sum%i==0)
			return false;
	}
	return true;
}

void dfs(int x,int start)
{

	if(x>k)
	{
		int sum=0;
		for(int i=1;i<=k;i++)
		{
			sum+=arr[i];
		}
		if(is_prim(sum))
		{
			res++;
		}
		return;
	}

	for(int i=start;i<=n;i++)
	{
		arr[x] = q[i];
		dfs(x+1,i+1);
		arr[x] = 0;
	}
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>q[i];
	dfs(1,1);
	printf("%d", res);
	return 0;
}