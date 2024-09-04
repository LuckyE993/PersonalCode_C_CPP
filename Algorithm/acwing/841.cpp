//
// Created by LuckyE on 2024/9/4.
//
#include "iostream"

using namespace std;
const int N = 100010, P = 131;//P: 131 or 13331
typedef unsigned long long ULL;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	int n, m;
	cin >> n >> m;
	p[0] = 1;
	scanf("%s", str + 1);

	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}
	while(m--)
	{
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(get(l1,r1)==get(l2,r2))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}