//
// Created by LuckyE on 2024/2/22.
//
#include "iostream"
#include "algorithm"
using namespace std;

int number_N;
int number_sum;
const int N = 1e5+10;
int a[N];

int main()
{
	cin>>number_N;
	cin>>number_sum;
	for(int i=0;i<number_N;i++)
		cin>>a[i];

	for(int i=0;i<number_sum;i++)
	{
		next_permutation(a,a+number_N);
	}
	for(int i=0;i<number_N;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}