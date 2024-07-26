//
// Created by LuckyE on 2024/7/17.
//
#include "iostream"

using namespace std;
int a[100010];
int merge_temp[100010];

void merge_sort(int q[],int l,int r)
{
	//分治法
	//分
	if(l>=r)//分到最小
		return;
	int mid = l+r >>1;
	//递归，一直到最后
	merge_sort(q,l,mid), merge_sort(q,mid+1,r);

	//治
	int i=l,j=mid+1,k=0;//i为左半边开始位置，j为右半边开始位置，k为暂时的数组索引从零开始
	while(i<=mid && j<=r)
	{
		if(q[i]<=q[j])
			merge_temp[k++]=q[i++];
		else
			merge_temp[k++]=q[j++];
	}
	while(i<=mid)
		merge_temp[k++]=q[i++];
	while(j<=r)
		merge_temp[k++]=q[j++];

	//copy to original q[]
	for(int i=l,k=0;i<=r;i++,k++)
		q[i]=merge_temp[k];

}

void quick_sort(int q[],int l,int r)
{
	if(l>=r)
		return;
	int i=l-1,j=r+1,x=q[(l+r)>>1];

	while(i<j)
	{
		do i++;
		while(q[i]>x);
		do j--;
		while (q[j]<x);
		if(i<j)
			swap(q[i],q[j]);
	}

	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}


int main()
{
//	int num;
//	cin>>num;
//	for(int i=0;i<num;i++)
//	{
//		cin>>a[i];
//	}
//
//	// merge_sort(a,0,num-1);
//	// quick_sort(a,0,num-1);
//
//	for(int i=0;i<num;i++)
//	{
//		cout<<a[i]<<" ";
//	}

	int number;
	scanf("%d",&number);
	int i=0,j=0;


	return 0;
}