#include "iostream"

using namespace std;

int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);

	int i,j;
	for(i=0;b[i]!='\0';i++)
	{
		j = a.find(b[i]);
		if(j!=-1)
		{
			a.erase(j,1);
			i--;
		}
	}
	cout<<a<<endl;
	return 0;
}