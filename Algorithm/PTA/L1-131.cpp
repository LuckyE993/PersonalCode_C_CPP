//
// Created by LuckyE on 2024/8/21.
//
/*据说一个人的标准体重应该是其身高（单位：厘米）减去100、再乘以0.9所得到的公斤数。
 * 真实体重与标准体重误差在10%以内都是完美身材（即 | 真实体重 − 标准体重 | < 标准体重×10%）。
 * 已知 1 公斤等于 2 市斤。现给定一群人的身高和实际体重，请你告诉他们是否太胖或太瘦了。
 *
 * 输入第一行给出一个正整数N（≤ 20）。
 * 随后N行，每行给出两个整数，分别是一个人的身高H（120 < H < 200；单位：厘米）
 * 和真实体重W（50 < W ≤ 300；单位：市斤），其间以空格分隔。
 * */

#include "iostream"
#include "vector"

using namespace std;

struct Person
{
	float weight;
	float height;
};

int main()
{
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		double standard_weight,height,weight;
		cin>>height>>weight;
		standard_weight = (height - 100)*0.9*2;
		if( abs(standard_weight-weight)<standard_weight*0.1 )
		{
			cout<<"You are wan mei!"<<endl;
		}
		else if((weight - standard_weight) >= standard_weight*0.1)
		{
			cout<<"You are tai pang le!"<<endl;
		}
		else
		{
			cout<<"You are tai shou le!"<<endl;
		}

	}

	return 0;
}

