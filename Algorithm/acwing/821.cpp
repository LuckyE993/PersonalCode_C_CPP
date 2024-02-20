//
// Created by LuckyE on 2024/2/20.
//
#include <bits/stdc++.h>
using namespace std;
int n;
int Fibnacci(int x)
{
	if(x==1)
	{
		return 1;
	}
	if(x==2)
	{
		return 1;
	}


	return Fibnacci(x-1)+ Fibnacci(x-2);
}

int main()
{
	cin>>n;
	cout << Fibnacci(n);
	return 0;
}