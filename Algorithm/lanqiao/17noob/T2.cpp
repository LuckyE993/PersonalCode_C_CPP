//
// Created by LuckyE on 2024/8/25.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int sum_a, sum_b;
int n;


int main()
{
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = -1 * a[i];
	}

	sort(a.begin(), a.begin() + n);
	sort(b.begin(), b.begin() + n);

	int size = (int)a.size();

	while (size)
	{
		size--;
		sum_a += a.back();
		a.pop_back();
		if (size)
		{
			sum_b += b.back();
			b.pop_back();
			size--;
		}
	}

	cout << sum_a - sum_b << endl;
	return 0;
}