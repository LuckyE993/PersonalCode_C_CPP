//
// Created by LuckyE on 2024/8/21.
//
#include "iostream"
#include "cmath"
#include "algorithm"

using namespace std;
typedef long long ll;

struct Number
{
	ll upper, downer;
};
Number number[110];

bool cmp(Number number1, Number number2)
{
	return number1.downer < number2.downer;
}

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;  // 先除再乘防止溢出
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char divide;
		cin >> number[i].upper >> divide >> number[i].downer;
	}

	ll common_lcm = 1;
	for (int i = 0; i < n; ++i)
	{
		common_lcm = lcm(number[i].downer, common_lcm);
	}


	// 通分阶段
	for (int i = 0; i < n; ++i)
	{
		number[i].upper *= common_lcm / number[i].downer;
		number[i].downer = common_lcm;
	}

	// 分子和
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += number[i].upper;
	}

	if(sum == 0) // 最后一个评测点
	{
		cout<<"0"<<endl;
		return 0;
	}

	ll common_gcd = gcd(abs(sum), abs(common_lcm));

	ll up = sum / common_gcd;
	ll down = common_lcm / common_gcd;

	if (up / down != 0)
	{
		ll last = up % down;
		if (last != 0)
		{
			cout << up / down << " " << last << "/" << down << endl;

		}
		else
		{
			cout << up / down << endl;
		}
	}
	else
	{
		cout << up << "/" << down << endl;
	}

	return 0;
}

