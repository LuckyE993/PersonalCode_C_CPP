
#include "iostream"

using namespace std;
const int N = 1e6 + 10;
int n_max;
int ans[11];
int index;
int out[N][11];

void dfs(int pos, int now_sum)
{
	if (now_sum > n_max)
	{
		return;
	}
	if (pos > 10)
	{
		if (now_sum == n_max)
		{
			index++;
			for (int pos_copy = 1; pos_copy <= 10; pos_copy++)
			{
				out[index][pos_copy] = ans[pos_copy];
			}

		}
		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		ans[pos] = i;
		dfs(pos + 1, now_sum + i);
		ans[pos] = 0;
	}

}

int main()
{
	cin >> n_max;
	dfs(1, 0);

	if (n_max>30||n_max<10)
	{
		cout << "0" << endl;
		return 0;
	}

	cout << index << endl;

	for (int index_out = 1; index_out <= index; index_out++)
	{
		for (int i = 1; i <= 10; i++)
			cout << out[index_out][i] << " ";
		if(index_out!=index)
			cout << endl;
	}
	return 0;
}













