//
// Created by LuckyE on 2024/8/27.
//
#include "iostream"
#include "cstring"
#include "algorithm"

using namespace std;
const int N = 1e5 + 10;
const int M = 2 * N;

int e[M], ne[M], h[N], idx;
int n, m;
int d[N], q[N];

void add_edge(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int bfs()
{
	int hh, tt;
	hh = tt = 0;

	q[0] = 1;
	memset(d, -1, sizeof d);
	d[1]=0;


	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] != -1)
				continue;
			else
			{
				d[j] = d[t] + 1;
				q[++tt] = j;
			}

		}
	}

	return d[n];
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		add_edge(a, b);
	}

	cout<<bfs()<<endl;
}