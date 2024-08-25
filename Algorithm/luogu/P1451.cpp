//
// Created by LuckyE on 2024/8/25.
//
#include "iostream"

using namespace std;

const int N = 110;
int n, m;
bool st[N][N];
char map[N][N];
int sum;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0 };

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a > n - 1 || b < 0 || b > m - 1)
			continue;
		if (st[a][b])
			continue;
		if (map[a][b] == '0')
			continue;

		st[a][b] = true;
		dfs(a, b);
	}
}

int main()
{
	int res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] != '0' && !st[i][j])
			{
				dfs(i, j);
				res++;
			}

		}
	}
	cout<<res<<endl;
	return 0;
}