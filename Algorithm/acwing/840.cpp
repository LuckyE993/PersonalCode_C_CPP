//
// Created by LuckyE on 2024/9/4.
//
#include "iostream"
#include "cstring"

using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

const int null = 0x3f3f3f3f, OpenN = 200003;
int open[OpenN];


bool zipper_find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
	{
		if (e[i] == x)
			return true;
	}
	return false;
}

void zipper_insert(int x)
{

	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

int open_find(int x)
{
	int k = (x % OpenN + OpenN) % OpenN;
	while (open[k] != x && open[k] != null)
	{
		k++;
		if (k == OpenN)
			k = 0;
	}
	return k;
}


int main()
{
	int n, x = 0;
	cin >> n;

	memset(h, -1, sizeof h);
	memset(open, 0x3f, sizeof open);

	char q[2];
	while (n--)
	{
		scanf("%s%d", q, &x);
//		if (q[0] == 'I')
//		{
//			zipper_insert(x);
//		}
//		else
//		{
//			if (zipper_find(x))
//			{
//				cout << "Yes" << endl;
//			}
//			else
//			{
//				cout << "No" << endl;
//			}
//		}
		int pos = open_find(x);
		if (q[0] == 'I')
		{
			open[pos] = x;

		}
		else
		{
			if (open[pos] == x)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}

	}


	return 0;
}