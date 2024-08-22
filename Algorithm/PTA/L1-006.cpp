//
// Created by LuckyE on 2024/8/21.
// 注意long long 范围
//
/*
 * 一个正整数 N 的因子中可能存在若干连续的数字。
 * 例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。
 * 给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。
 *
 *
 * */


#include "cmath"
#include "iostream"
using namespace std;
int main()
{
	long long Maxlength = 0,b = 0,n;
	cin>>n;
	int m = sqrt(n);
	for(int i=2;i<=m;i++)
	{
		long long sum = 1;
		for(int j=i;sum*j<=n;j++)
		{
			sum *= j;
			if(n%sum == 0 && (j-i+1) > Maxlength)
			{
				b = i;
				Maxlength = j-i+1;
			}
		}
	}

	if(b == 0)
	{
		cout<<"1"<<endl;
		cout<<n<<endl;
	}
	else
	{
		cout<<Maxlength<<endl;
		bool flag = false;
		for(int i=b;i<b+Maxlength;i++)
		{
			if(flag)
			{
				cout<<"*";
			}
			cout<<i;
			flag = true;
		}
		cout<<endl;
	}

	return 0;
}