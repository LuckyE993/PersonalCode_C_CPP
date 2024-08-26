#include "iostream"
#include "cstring"
#include "queue"

using namespace std;
int n, m;
const int N = 200;

int a[N][N];
int dis[N][N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

typedef pair<int, int> PII;
queue<PII> q;

void bfs(int start_x, int start_y)
{
	dis[start_x][start_y] = 0;
	q.push({ start_x, start_y });

	while (q.size())
	{
		PII now = q.front();
		q.pop();
		int sx = now.first, sy = now.second;
		for (int i = 0; i < 4; ++i)
		{
			int x = sx + dx[i], y = sy + dy[i];
			if (x > n - 1 || x < 0 || y > m - 1 || y < 0)
			{
				continue;
			}
			if (a[x][y] != 0)
			{
				continue;
			}
			if (dis[x][y] >0)
			{
				continue;
			}

			dis[x][y] = dis[sx][sy] + 1;
			q.push({ x, y });

			if(x == n-1&&y==m-1)
			{
				cout<<dis[x][y]<<endl;
				return;
			}

		}
	}


}


int main()
{
	cin >> n >> m;
	memset(dis, -1, sizeof dis);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	// 因为不是从1开始，所以需要加一个特判。
	if(n==1&&m==1)
	{
		cout<<0<<endl;
		return 0;
	}

	bfs(0,0);
	return 0;
}
