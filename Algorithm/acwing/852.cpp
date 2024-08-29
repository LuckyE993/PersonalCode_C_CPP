//
// Created by LuckyE on 2024/8/29.
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;

const int N = 1e6 + 10;
int h[N], e[N], ne[N], w[N], dist[N], idx,cnt[N];
bool st[N];
typedef pair<int, int> PII;

int n, m, k;

void add_edge(int a, int b, int c)
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx++;
}

bool SPFA()
{
	queue<int> q;

	for(int i=1;i<=n;i++)
	{
		q.push(i);
		st[i] = false;
	}

	while (q.size())
	{
		auto t = q.front();
		q.pop();
		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];

			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t]+1;

				if(cnt[j]>n)
				{
					return true;
				}

				if(!st[j])
				{
					st[j] = true;
					q.push(j);
				}
			}

		}


	}

	return false;

}

int main()
{
	memset(h,-1,sizeof h);

	cin >> n >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(a, b, c);

	}

	if(SPFA())
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}

	return 0;
}