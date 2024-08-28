//
// Created by LuckyE on 2024/8/28.
//
#include "iostream"
#include "cstring"
#include "algorithm"

using namespace std;
const int N = 1e5 + 10;

int h[N], hp[N], ph[N], cnt;

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void up(int u)
{
	while (u / 2 && h[u / 2] > h[u])
	{
		heap_swap(u, u / 2);
		u /= 2;
	}
}

void down(int u)
{
	int t = u;
	if (u * 2 <= cnt && h[u * 2] < h[t])
	{
		t = u * 2;
	}
	if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
	{
		t = u * 2 + 1;
	}
	if (u != t)
	{
		heap_swap(u, t);
		down(t);
	}
}


int main()
{
	int n, m = 0;
	cin >> n;
	while (n--)
	{
		char q[10];
		cin >> q;
		if (!strcmp(q, "I"))
		{
			int x;
			cin >> x;
			cnt++;
			m++;
			ph[m] = cnt, hp[cnt] = m;
			h[cnt] = x;
			up(cnt);
		}
		else if (!strcmp(q, "PM"))
		{
			cout << h[1] << endl;
		}
		else if (!strcmp(q, "DM"))
		{
			heap_swap(1, cnt);
			cnt--;
			down(1);
		}
		else if (!strcmp(q, "D"))
		{
			int k;
			cin >> k;
			k = ph[k];
			heap_swap(k, cnt);
			cnt--;
			down(k);
			up(k);
		}
		else if (!strcmp(q, "C"))
		{
			int k, x;
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			down(k);
			up(k);
		}

	}
	return 0;
}