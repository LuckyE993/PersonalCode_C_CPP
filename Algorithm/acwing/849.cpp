//
// Created by LuckyE on 2024/8/27.
//
#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;
const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int dijkstra()
{
	dist[1] = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		int t = -1;
		for (int j = 1; j <= n; ++j)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
			{
				t = j;
			}
		}

		for (int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j],dist[t]+g[t][j]);
		}
		st[t] = true;
	}

	if(dist[n] == 0x3f3f3f3f)
	{
		return -1;
	}
	else
	{
		return dist[n];
	}

}

int main()
{
	memset(dist, 0x3f, sizeof dist);
	memset(g, 0x3f, sizeof g);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		g[a][b] = min(g[a][b], c);
	}

	int ans = dijkstra();
	cout<<ans<<endl;

	return 0;
}