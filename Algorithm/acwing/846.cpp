//
// Created by LuckyE on 2024/8/27.
//
#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;
const int N = 1e5 + 10;
const int M = 2 * N;

int h[N], e[M], ne[M], idx;
bool st[N];
int n;
int ans = N;

void add_edge(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dfs(int root)
{
	int sum = 0, size = 0;
	st[root] = true;

	for (int i = h[root]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (st[j])
			continue;
		int s = dfs(j);
		size = max(size, s);
		sum += s;
	}

	size = max(size, n - sum - 1);
	ans = min(size, ans);

	return sum + 1;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	int a, b;
	for(int i=0;i<n-1;i++)
	{
		cin >> a >> b;
		add_edge(a, b);
		add_edge(b, a);
	}
	dfs(1);
	cout<<ans<<endl;

	return 0;
}
