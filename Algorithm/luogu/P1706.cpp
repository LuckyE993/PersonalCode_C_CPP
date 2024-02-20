//
// Created by LuckyE on 2024/2/20.
//
#include "iostream"
using namespace std;
const int N=1e5+10;
int n;
bool st[N];
int arr[N];

void dfs(int x)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<"    "<<arr[i];
		}
		cout<<endl;
		return;
	}


	for(int i=1;i<=n;i++)
	{
		if(!st[i])
		{
			st[i] = true;
			arr[x] = i;
			dfs(x+1);
			st[i]= false;
			arr[x] = 0;
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}