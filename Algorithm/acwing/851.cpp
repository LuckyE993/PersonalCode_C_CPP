//
// Created by LuckyE on 2024/8/28.
//
#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"

using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], dist[N], idx;
bool st[N],flag;
int n, m;

typedef pair<int, int> PII;

void add_edge(int a, int b, int c)
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx++;
}

int SPFA()
{
	memset(dist, 0x3f, sizeof dist);
	queue<PII> q;
	q.push({ 0, 1 });
	st[1] = true;
	dist[1] = 0;

	while (q.size())
	{
		auto t = q.front();
		q.pop();

		int pos = t.second;
		st[pos] = false;

		for (int i = h[pos]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[pos] + w[i])
			{
				dist[j] = dist[pos] + w[i];
				if (!st[j])
				{
					st[j] = true;
					q.push({ dist[j], j });
				}
			}
		}
	}

	if (dist[n] == 0x3f3f3f3f)
	{
		cout<<"impossible"<<endl;
		flag = false;
	}
	else
	{
		flag = true;
		return dist[n];
	}
}

int main()
{
	memset(h,-1,sizeof h);
	cin >> n >> m;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add_edge(x, y, z);

	}

	int ans = SPFA();
	if (flag)
	{
		cout << ans << endl;
	}

	return 0;
}
