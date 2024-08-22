//
// Created by LuckyE on 2024/8/21.
// STL set 用法
//
/*
 *
 *  输入样例：
	18013820100
	输出样例：
	int[] arr = new int[]{8,3,2,1,0};
	int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};
 *
 * */

#include "iostream"
#include "set"
using namespace std;
int main()
{
	string snumber;
	cin>>snumber;

	set<int,greater<int>> numbers;
	for(char c:snumber)
	{
		numbers.insert(c - '0');
	}

	cout<<"int[] arr = new int[]{";
	bool flag = false;
	for(const int& num :numbers)
	{
		if(flag)
			cout<<",";
		cout<<num;
		flag = true;
	}
	cout<<"};"<<endl;

	cout<<"int[] index = new int[]{";
	flag = false;
	for(char c : snumber)
	{
		if(flag)
			cout<<",";
		auto it = numbers.find(int(c-'0'));
		cout<<std::distance(numbers.begin(),it);
		flag = true;
	}
	cout<<"};"<<endl;

	return 0;
}