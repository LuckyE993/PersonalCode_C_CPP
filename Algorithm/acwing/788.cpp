//
// Created by LuckyE on 2024/7/17.
//
//
// Created by LuckyE on 2024/7/17.
//
#include "iostream"

using namespace std;
int a[100010];
int merge_temp[100010];
long long ans;
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
		{
			merge_temp[k++]=q[j++];
			ans+=(mid+1-i);//题目核心重点
			/*
			 * 当序列为 1256|3478时
			 * 出现 5>3 时就证明从5开始直到mid都是逆序对
			 * 因此，可以通过mid+1-i来直接加上
			 * */
		}
	}

	while(i<=mid)
		merge_temp[k++]=q[i++];

	while(j<=r)
		merge_temp[k++]=q[j++];

	//copy to original q[]
	for(int i=l,k=0;i<=r;i++,k++)
		q[i]=merge_temp[k];

}

int main()
{
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>a[i];
	}

	merge_sort(a,0,num-1);

	cout<<ans<<endl;
	return 0;
}