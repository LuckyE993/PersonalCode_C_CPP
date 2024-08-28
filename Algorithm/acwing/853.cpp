//
// Created by LuckyE on 2024/8/28.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"

using namespace std;
const int N = 510, M = 1e5 + 10;

struct Edge
{
	int from, to, weight;
};

Edge edge[M];
int n, m, k, dist[N], last[N];

void bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);

	dist[1] = 0;
	for (int i = 1; i <= k; i++)
	{
		memcpy(last, dist, sizeof dist);
		for (int j = 0; j < m; j++)
		{
			auto e = edge[j];
			dist[e.to] = min(dist[e.to], last[e.from] + e.weight);
		}
	}

}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;

		edge[i] = { x, y, z };

	}

	bellman_ford();

	if(dist[n]>0x3f3f3f3f/2)
	{
		cout<<"impossible"<<endl;
	}
	else
	{
		cout<<dist[n]<<endl;
	}
	return 0;
}