//
// Created by LuckyE on 2024/8/25.
//
#include "iostream"
using namespace std;

const int dx[8]={-1,-2,-2,-1,1,2,2,1};
const int dy[8]={2,1,-1,-2,2,1,-1,-2};

int n,m,x,y;

struct Map
{
	bool visit = false;
	int step = 100000;
};

Map map[420][420];

void dfs(int x,int y,int now_step)
{
	if(x<1||y<1||x>n||y>m)
		return;

	for(int i=0;i<8;i++)
	{

		if(map[x][y].step>now_step)
			map[x][y].step = now_step;
		dfs(x+dx[i],y+dy[i],now_step+1);
	}
}

int main()
{
	cin>>n>>m>>x>>y;

	// dfs(x,y,0);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<map[i][j].step<<" ";
		}
		cout<<endl;
	}

	return 0;
}