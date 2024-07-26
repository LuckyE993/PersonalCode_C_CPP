//
// Created by LuckyE on 2024/7/26.
//
#include "iostream"
#include "./inc/Sales_item.h"

#define CONFIG_ITEM "1.6"

int main()
{
	if (0)
	{
		// use inout_files/add_item
		Sales_item item1,item2;
		std::cin>>item1>>item2;
		if(item1.isbn() == item2.isbn())
		{
			std::cout<<item1+item2<<std::endl;
			return 0;
		}
		else
		{
			std::cerr<<"ISBN is not equal"<<std::endl;
			return -1;
		}
	}

	if(1)
	{
		// use inout_files/book_sales.txt
		Sales_item item_total;
		if(std::cin >> item_total)
		{
			Sales_item item_current;
			while(std::cin >> item_current)
			{
				if(item_total.isbn() == item_current.isbn())
				{
					item_total += item_current;
				}
				else
				{
					std::cout<<item_total<<std::endl;
					item_total = item_current;
				}
			}
			std::cout<<item_total<<std::endl;
			return 0;
		}
		else
		{
			std::cerr<<"No Books ?!"<<std::endl;
			return -1;
		}
	}

	return 0;
}