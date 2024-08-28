//
// Created by LuckyE on 2024/8/26.
//
#include <unordered_map>
#include "iostream"
#include "map"
#include "queue"
#include "algorithm"
#include "string"

using namespace std;

int bfs(string s1)
{
	queue<string> q;
	unordered_map<string, int> d;
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };
	string s_template = "12345678x";
	q.push(s1);
	d[s1] = 0;

	while (q.size())
	{
		string s = q.front();
		q.pop();

		int dis = d[s];
		if (s == s_template)
			return dis;
		int k = s.find('x');
		int x = k / 3, y = k % 3;

		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				swap(s[k], s[a * 3 + b]);
				if (!d.count(s))
				{
					d[s] = dis + 1;
					q.push(s);
				}
				swap(s[k], s[a * 3 + b]);//恢复现场，进行下一次移动
			}


		}

	}
	return -1;

}

int main()
{
	string input;
	for (int i = 0; i < 9; ++i)
	{
		char c;
		cin >> c;
		input += c;
	}

	cout << bfs(input) << endl;

	return 0;
}