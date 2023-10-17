//
// Created by Lucky_E on 2023-07-23.
//
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