//
// Created by LuckyE on 2024/8/27.
//
#include "iostream"
#include "cstring"
#include "algorithm"

using namespace std;
const int N = 1e5 + 10;
const int M = 2 * N;
int h[N], e[M], ne[M], idx;
int d[N], q[N];
int n, m;

void add_edge(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool topsort()
{
	int hh = 0, tt = -1;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0)
		{
			q[++tt] = i;
		}
	}
	while(hh<=tt)
	{
		int t = q[hh++];

		for(int i=h[t];i!=-1;i = ne[i])
		{
			int j = e[i];
			d[j]--;
			if(d[j]==0)
			{
				q[++tt] = j;
			}
		}
	}
	if(tt == n-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	memset(d, 0, sizeof d);
	memset(h,-1,sizeof h);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
		d[b]++;
	}

	if(topsort())
	{
		for(int i=0;i<n;i++)
		{
			cout<<q[i]<<" ";
		}

	}
	else
	{
		cout<<"-1"<<endl;
	}


	return 0;
}
