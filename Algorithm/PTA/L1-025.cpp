//
// Created by LuckyE on 2024/8/22.
//
#include "iostream"

using namespace std;

bool isLegal(string str, int* number)
{
	if (str.length() == 0)
		return false;
	else
	{
		for(char c:str)
		{
			if(!isdigit(c))
			{
				return false;
			}
		}

		*number = stoi(str);
		if(*number>=1 && *number<=1000)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

int main()
{
	string str;
	getline(cin, str);
	int pos = -1;
	string substr1, substr2;
	for (char c: str)
	{
		pos++;
		if (c == ' ')
		{
			substr1 = str.substr(0, pos);
			substr2 = str.substr(pos + 1, str.length() - pos);
			break;
		}
	}

	int left = 0, right = 0;
	bool left_legal=isLegal(substr1, &left),right_legal=isLegal(substr2, &right);
	if (left_legal && right_legal)
	{
		cout<<left<<" + "<<right<<" = "<<left+right<<endl;
	}
	else
	{
		if(left_legal)
		{
			cout<<left;
		}else
		{
			cout<<"?";
		}
		cout<<" + ";
		if(right_legal)
		{
			cout<<right;
		}else
		{
			cout<<"?";
		}
		cout<<" = ?"<<endl;

	}

	return 0;
}