//
// Created by LuckyE on 2024/8/21.
// L1-019 谁先倒
//
/*
 * 如果谁比划出的数字正好等于两人喊出的数字之和，谁就输了，输家罚一杯酒。
 * 两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。
 *
 *
 * */

#include "iostream"
using namespace std;
int main()
{
	int max_a,max_b;
	cin>>max_a>>max_b;
	int cur_a=0,cur_b = 0;
	int N;
	cin>>N;

	while(N-- && cur_a<= max_a && cur_b<=max_b)
	{
		int a_call,a_hand,b_call,b_hand;
		cin>>a_call>>a_hand>>b_call>>b_hand;

		int sum = a_call+b_call;
		if(a_hand == sum && b_hand == sum )
		{
			continue;
		}
		if(a_hand == sum)
		{
			cur_a++;
		}
		if(b_hand == sum)
		{
			cur_b++;
		}

	}

	if(cur_a > max_a)
	{
		cout<<"A"<<endl;
		cout<<cur_b<<endl;
	}
	else
	{
		cout<<"B"<<endl;
		cout<<cur_a<<endl;
	}

	return 0;
}