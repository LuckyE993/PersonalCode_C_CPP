//
// Created by LuckyE on 2024/8/23.
//
#include "iostream"

using namespace std;

/*
 * 你这段代码的问题主要出在 getline 和 cin 的混用上。
 * 当你使用 cin >> all >> num;后，输入流中还会残留一个换行符，
 * 这会导致 getline 在第一次调用时直接读取这个换行符并返回一个空字符串，而不是你期望的完整的一行输入。
 *
 * */
int main()
{
	int all, num;
	cin >> all >> num;
	cin.ignore();
	string question;
	while (all--)
	{
		getline(cin, question);

		if ((question.find("easy") != std::string::npos) ||
			(question.find("qiandao") != std::string::npos))
		{

			continue;

		}
		else
		{
			if ((num--) == 0)
			{
				cout << question << endl;
				return 0;
			}
		}


	}

	cout << "Wo AK le" << endl;
	return 0;
}