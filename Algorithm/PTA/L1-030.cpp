//
// Created by LuckyE on 2024/8/21.
//
/*
 * 输入第一行给出正偶数N（≤50），即全班学生的人数。
 * 此后N行，按照名次从高到低的顺序给出每个学生的性别（0代表女生，1代表男生）和姓名（不超过8个英文字母的非空字符串），
 * 其间以1个空格分隔。
 * 这里保证本班男女比例是1:1，并且没有并列名次。
 *
 * */
#include "iostream"
#include "vector"
using namespace std;

struct Student
{
	bool gender;
	string name;
	bool used;
};

std::vector<Student> student(50);

int main()
{
	int N;
	cin>>N;



	for(int i=0;i<N;i++)
	{
		cin>>student[i].gender>>student[i].name;
	}

	int l = 0;
	int r = N-1;

	for(l=0;l<N;l++)
	{
		if(student[l].used == true)
			break;
		cout<<student[l].name<<" ";
		for(r = N-1;r>0;r--)
		{
			if(student[r].gender!=student[l].gender && !student[r].used)
			{
				cout<<student[r].name<<endl;
				student[r].used = true;
				break;
			}
		}
		student[l].used = true;
	}

	return 0;
}