//
// Created by LuckyE on 2024/8/28.
//
#include "iostream"

using namespace std;
const int N = 1e5 + 10;
int n, m;
int h[N];
int range = 0;

void down(int u)
{
	int t = u;
	if (u * 2 <= range && h[u * 2] < h[t])
	{
		t = u * 2;
	}
	if (u * 2 + 1 <= range && h[u * 2 + 1] < h[t])
	{
		t = u * 2 + 1;
	}

	if (h[t] != h[u])
	{
		swap(h[t], h[u]);
		down(t);
	}

}

void up(int u)
{
	while (u / 2 != 0 && h[u / 2] > h[u])
	{
		swap(h[u / 2], h[u]);
		u /= 2;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i];
	}
	range = n;
	for (int i = n / 2; i; i--)
	{
		down(i);
	}

	for (int i = 1; i <= m; ++i)
	{
		cout<<h[1]<<" ";
		h[1] = h[range];
		range-- ;
		down(1);
	}

	return 0;
}