//
// Created by LuckyE on 2024/4/11.
//
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
const int N = 1e5+10;
int st[N];
int a[15];
int n;

struct Node{
	int t;
	int d;
	int l;
};

Node  node[15];

int  main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(st, 0,sizeof st);
		cin>>n;

		for(int i=0;i<n;i++)
		{
			cin>>node[i].t>>node[i].d>>node[i].l;
		}



	}
	return 0;
}