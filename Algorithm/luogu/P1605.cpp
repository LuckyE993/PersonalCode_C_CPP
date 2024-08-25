//
// Created by LuckyE on 2024/8/25.
//
#include "iostream"

using namespace std;

bool map[7][7], temp[7][7];
int n, m, t, sx, sy, fx, fy;
int sum;

int dir_x[] = {1,0,-1,0};
int dir_y[] = {0,1,0,-1};

void dfs(int x, int y)
{
	if (x == fx && y == fy && map[x][y])
	{
		sum++;
		return;
	}
	if(!map[x][y] || temp[x][y])
	{
		return;
	}

	for(int i=0;i<4;i++)
	{
		temp[x][y] = true;
		dfs(x+dir_x[i],y+dir_y[i]);
		temp[x][y] = false;
	}

}

int main()
{
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			map[i][j] = true;

	while (t--)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = false;
	}
	dfs(sx,sy);
	cout<<sum<<endl;
	return 0;
}