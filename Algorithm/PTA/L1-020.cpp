//
// Created by LuckyE on 2024/8/21.
// 使用 set 模板来统计只出现一次的
//
/*
 * 输入第一行给出一个正整数N（≤100），是已知朋友圈的个数；
 * 随后N行，每行首先给出一个正整数K（≤1000），为朋友圈中的人数，然后列出一个朋友圈内的所有人——
 * 为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；
 * 之后给出一个正整数M（≤10000），为待查询的人数；
 * 随后一行中列出M个待查询的ID，以空格分隔。
 * 但题目保证所有K超过1的朋友圈里都至少有2个不同的人。
 * */

#include <set>
#include "iostream"
using namespace std;

int main()
{
	int N,M;
	cin>>N;

	set<string > s,ans;
	string str;
	while(N--)
	{
		int K;
		cin>>K;

		if(K>=2)
		{
			while (K--)
			{
				cin>>str;
				s.insert(str);
			}
		}
		else
		{
			cin>>str;
		}
	}

	int flag = 0;
	cin>>M;
	while(M--)
	{
		cin>>str;
		if(s.find(str) == s.end() && ans.find(str) == ans.end())
		{
			if(flag)
			{
				cout<<" ";
			}
			cout<<str;

			s.insert(str);
			flag++;
		}
	}



	if(flag == 0)
	{
		cout<<"No one is handsome";
	}
	return 0;
}
