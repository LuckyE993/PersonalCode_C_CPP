//
// Created by LuckyE on 2024/8/25.
//
#include "iostream"

using namespace std;
const int N = 110;
int n, m;

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { -1, 0, 1, 1, -1, 1, -1, 0 };

char map[N][N];
bool st[N][N];

void dfs(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int a = dx[i] + x, b = dy[i] + y;
		if (a < 0 || a > n - 1 || b < 0 || b > m - 1)
			continue;
		if (map[a][b] != 'W')
			continue;
		if (st[a][b])
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
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'W' && st[i][j] != true)
			{
				dfs(i, j);
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}