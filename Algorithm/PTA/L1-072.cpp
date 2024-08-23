//
// Created by LuckyE on 2024/8/23.
// woc 大模拟
//
#include "iostream"

using namespace std;

pair<int, bool> board[3][3];
int money[30] = {0,0,0,0,0,0,
				 10000,36,720,360,80,252,
				 108,72,54,180,72,180,
				 119,36,306,1080,144,1800,3600

};

int main()
{
	for (auto & i : board)
	{
		for (auto & j : i)
		{
			cin >> j.first;
			if (j.first == 0)
			{
				j.second = true;
			}
		}
	}

	for(int i=0;i<3;i++)
	{
		int x,y;
		cin>>x>>y;

		board[x][y].second = true;
		cout<<board[x][y].first<<endl;

	}

	int choose;
	cin>>choose;
	switch (choose)
	{
	case 3:

	}

	for (auto& i: board)
	{
		for (auto& j: i)
			cout << j.first << " ";
		cout << endl;
	}
	return 0;
}