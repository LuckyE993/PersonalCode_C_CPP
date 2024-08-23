//
// Created by LuckyE on 2024/2/20.
//
#include "iostream"
#include "iomanip"

using namespace std;
const int N=1e5+10;
int n;
bool st[N];
int out[N];

void dfs(int x)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
			cout<<setw(5)<<out[i];
		cout<<endl;
	}

	for(int i=1;i<=n;i++)
	{
		if(!st[i])
		{
			st[i] = true;
			out[x] = i;
			dfs(x+1);
			out[x] = 0;
			st[i] = false;
		}
	}

}

int main()
{
	cin >> n;
	dfs(1);
	return 0;
}
