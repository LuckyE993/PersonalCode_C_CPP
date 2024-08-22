//
// Created by LuckyE on 2024/8/22.
//
#include "iostream"
using namespace std;

int g,p,l,t;

int main()
{
	string str;
	cin>>str;

	for(char c:str)
	{
		if(c == 'G' || c == 'g')
		{
			g++;
		}
		if(c == 'P' || c == 'p')
		{
			p++;
		}
		if(c == 'L' || c == 'l')
		{
			l++;
		}
		if(c == 'T' || c == 't')
		{
			t++;
		}

	}
	while(g||p||l||t)
	{
		if(g)
		{
			cout<<"G";
			g--;
		}
		if(p)
		{
			cout<<"P";
			p--;
		}
		if(l)
		{
			cout<<"L";
			l--;
		}
		if(t)
		{
			cout<<"T";
			t--;
		}
	}

	return 0;
}

