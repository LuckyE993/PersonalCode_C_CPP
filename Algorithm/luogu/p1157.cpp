//
// Created by LuckyE on 2024/2/20.
//
#include "iostream"
#include <cstdio>
#include "iomanip"
using namespace std;
const int N = 1e5 + 10;
int out[N];
int n, r;

void dfs(int pos, int start)
{
	if (pos > r)
	{
		for (int i = 1; i <= r; ++i)
		{
			cout<<setw(3)<<out[i];
		}
		cout<<endl;
		return;
	}

	for(int i=start;i<=n;i++)
	{
		out[pos] = i;
		dfs(pos+1,i+1);
		out[pos] = 0;
	}



}

int main()
{

	cin >> n >> r;
	dfs(1, 1);
	return 0;
}