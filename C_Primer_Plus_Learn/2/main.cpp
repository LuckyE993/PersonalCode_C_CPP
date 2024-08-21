//
// Created by LuckyE on 2024/7/27.
//
#include "iostream"
//code 2.2 different scope variable
int reused = 42;

int main()
{
	//code 2.2 different scope variable
	int reused = 30;
	std::cout<<"inner scope reused is "<<reused<<std::endl;
	std::cout<<"global scope reused is "<<::reused<<std::endl;

	//code 2.3.1 reference .
	//reference is not an object
	int ival = 1024;
	int &refVal = ival;
	refVal = 512;
	int &refVal2 = refVal;
	refVal2 = 256;
	std::cout<<"refVal2 is bound with iVal ,it is "<<refVal2<<std::endl;

	//code 2.3.2 pointer;
	int *p1 = &ival;
	int *p2 = &refVal;
	std::cout<<"p1 is  "<<p1<<", p2 is "<<p2<<std::endl;
	std::cout<<"*p1 is "<<*p1<<std::endl;

	//Actually, it is easy to understand like "int* &refp1 = p1"
	int *&refp1 = p1;


	return 0;
}