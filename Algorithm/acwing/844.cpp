//
// Created by Lucky_E on 2023-07-23.
// Add new solution by Lucky_E on 2024-04-02.
//
//Solution1 Solution2
#define Solution1

#ifdef Solution1
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>


using namespace std;
typedef pair<int,int> PII;
queue<PII> q;

const int N = 110;
int g[N][N];
int dist[N][N];
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void bfs(int x1,int y1)
{
	q.push({x1,y1});
	dist[x1][y1] = 0;

	while(q.size())
	{
		auto t = q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<1||a>n||b<1||b>m)continue;
			if(dist[a][b]>0)continue;
			if(g[a][b])continue;

			dist[a][b] = dist[t.first][t.second] + 1;
			q.push({a,b});

			if(a==n&&b==m)
			{
				printf("%d\n",dist[n][m]);
				return;
			}

		}


	}
	printf("%d\n",dist[n][m]);
}

int main()
{
	memset(dist,-1,sizeof dist);//memset must in a function.
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}

	bfs(1,1);
	return 0;
}
#endif

#ifdef Solution2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y){};
};

int solve(int n, int m,vector<vector<int>>& maze);

int solve(int n,int m,vector<vector<int>>& maze)
{
    vector<vector<int>> moves(n, vector<int>(m,-1));
    moves[0][0] = 0;

    queue<Point> q;
    q.push(Point(0,0));

    vector<pair<int,int>> directions={{-1,0},{1,0},{0,1},{0,-1}};

    while(!q.empty())
    {
        Point current = q.front();
        q.pop();

        for(auto dir : directions)
        {
            int newx = current.x + dir.first;
            int newy = current.y + dir.second;

            if(newx>=0 && newx<n && newy>=0 && newy<m && maze[newx][newy]==0 && moves[newx][newy]==-1)
            {
                moves[newx][newy] = moves[current.x][current.y]+1;
                q.push(Point(newx,newy));
            }

        }
    }

    return moves[n-1][m-1];
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> maze(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            cin >> x;
            maze[i][j] = x;
        }
    }

    cout<<solve(n,m,maze)<<endl;

    return 0;
}

#endif