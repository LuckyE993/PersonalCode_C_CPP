//
// Created by LuckyE on 2024/1/17.
//
#include "bits/stdc++.h"
using namespace  std;
struct bign{
	int d[1000];
	int length;
	bign()
	{
		memset(d,0,sizeof (d));
		length = 0;
	}

};///

bign change(string str)
{
	bign a;
	a.length = str.length();
	for(int i=0;i<a.length;i++)
	{
		a.d[a.length-i]=str[i]-48;
	}
	return a;
}

bign Bign_add(bign a,bign b)
{
	bign c;
	c.length = 1;
	int x=0;
	while(c.length<=a.length||c.length<=b.length)
	{
		c.d[c.length] = a.d[c.length]+b.d[c.length]+x;
		x = c.d[c.length]/10;
		c.d[c.length] %= 10;
		c.length++;
	}
	c.d[c.length] = x;
	if(!c.d[c.length])
	{
		c.length--;
	}
	return c;
}

bign Bign_Sub(bign a,bign b)
{

}

int main()
{
	string s1,s2;
	s1 = "12345";
	s2 = "12345";
	bign b1,b2;
	b1 = change(s1);
	b2 = change(s2);
	bign sum;
	sum = Bign_add(b1,b2);
	for(int i=sum.length;i>=1;i--)
	{
		cout<<sum.d[i]<<" ";
	}

	return 0;
}