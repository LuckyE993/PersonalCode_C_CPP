//
// Created by LuckyE on 2024/4/6.
//
#include "iostream"

using namespace std;
const int N = 2e5+10;
char c[N];
int arr[N];
int n;
long long q;
int char_a='a';
//char c;
int sum;

int main()
{

	cin>>n>>q;

	c[0] = 'a';
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		arr[i]=(c[i]-char_a)-(c[i-1]-char_a);

	}

//	for(int i=1;i<=n;i++)
//		cout<<arr[i]<<" ";
//	cout<<endl;

	while(q--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		arr[l]+=x;
		arr[r+1]-=x;
	}

	for(int i=1;i<=n;i++)
	{
		sum+=arr[i];
		cout<<(char)(sum%26+char_a);
	}

	return 0;
}