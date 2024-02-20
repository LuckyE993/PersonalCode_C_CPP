#include <iostream>

using namespace std;

const int N = 11;

int n, m;
bool g[N][N], st[N];    //g表示朋友关系, st表示人是否使用过的状态
int pos[N];             //每个位置上是谁

int dfs(int u)
{
	if (u == n)         //n个人已经排满时
	{
		if (g[pos[n - 1]][pos[0]]) return 0;    //判断最后一人是否与第一人为朋友关系
		return 1;
	}

	int res = 0;
	for (int i = 1; i <= n; i ++ )              //题干中给出人是从编号1开始的
		if (!st[i] && !g[i][pos[u - 1]])        //该人没用过且与前一个人非朋友关系
		{
			pos[u] = i;
			st[i] = true;
			res += dfs(u + 1);
			st[i] = false;                      //还原现场
		}

	return res;
}

int main()
{
	cin >> n >> m;
	while (m -- )
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = true;       //朋友关系初始化
	}

	pos[0] = 1;                         //第一个人挂上去
	st[1] = true;                       //第一个人已经用过了

	cout << dfs(1) << endl;

	return 0;
}
