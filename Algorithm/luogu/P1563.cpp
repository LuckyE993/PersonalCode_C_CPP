//
// Created by LuckyE on 2024/1/17.
//
#include "bits/stdc++.h"
using namespace std;

struct Node{
	int head;
	string name;
};

struct Node a[100010];

int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++)
	{
		cin>>a[i].head;
		cin>>a[i].name;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i].head<<" ";
		cout<<a[i].name<<endl;
	}
	n--;
	bool cmd_dir;
	int cmd_num;
	int target=0;
	while(m--)
	{
		cin>>cmd_dir>>cmd_num;
		if(cmd_dir)
		{
			target=(cmd_dir*a[target].head)*cmd_num;

		}
	}

	return 0;
}