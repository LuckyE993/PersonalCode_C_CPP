//
// Created by LuckyE on 2024/8/28.
//
#include "iostream"
#include "cstring"
#include "algorithm"
#include "queue"

using namespace std;
const int N = 1e6 + 10;

int h[N], e[N], ne[N], w[N], dist[N], idx;
bool st[N];
typedef pair<int, int> PII;

int n, m;

void add_edge(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII>, greater<PII>> heap;

	dist[1] = 0;
	heap.push({ 0, 1 });

	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();

		int pos = t.second, distance = t.first;

		if (st[pos])
			continue;
		else
			st[pos] = true;

		for (int i = h[pos]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[pos] + w[i])
			{
				dist[j] = dist[pos] + w[i];
				heap.push({ dist[j], j });
			}
		}
	}

	if (dist[n] == 0x3f3f3f3f)
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
	memset(h, -1, sizeof h);
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add_edge(a,b,c);

	}

	cout<<dijkstra()<<endl;

	return 0;
}