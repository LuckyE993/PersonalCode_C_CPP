//
// Created by LuckyE on 2024/8/23.
//

/*
 * 
 *
 *  输入样例：
	2 3 10
	输出样例：
	2 3 6 1 8 6 8 4 8 4
 * */

#include "iostream"
using namespace std;
int i;
int main()
{
	string str = "";
	int a,b,n;
	cin>>a>>b>>n;
	str += to_string(a);
	str += to_string(b);
	int length;
	length = str.length();
	while(length<n)
	{
		int out;
		int a1 = str[i] - '0',a2 = str[i+1] - '0';

		out = a1*a2;
		str += to_string(out);
//		cout<<str<<endl;
		length = str.length();
		i++;
	}

	bool flag = false;

	for(int j=0;j<n;j++)
	{
		if(flag)
		{
			cout<<" ";
		}
		else
		{
			flag = true;
		}
		cout<<str[j];
	}
	return 0;
}