//
// Created by LuckyE on 2024/2/4.
//
#include "bits/stdc++.h"

using namespace std;
const int N=100010;
int son[N][26],cnt[N],idx;
string str;

void insert(string str)
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u])
		{
			son[p][u]= ++idx;

		}
		p=son[p][u];

	}
	cnt[p]++;
}
int query(string str)
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u])
		{
			return 0;
		}
		p=son[p][u];
	}
	return cnt[p];
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string op;
		cin>>op>>str;
		if(op[0]=='I')
		{
			insert(str);
		}
		else
		{
			int Cnt = query(str);
			cout<<Cnt<<endl;
		}
	}

	return 0;
}