#include  <iostream>
int a[10010];
int Search(int *q,int value)
{
    int left = 0,right =sizeof(q)-1;

    int temp=0;
    while(left<=right)
    {
        int middle = left + (right - left)/2;
        if(q[middle]<value)
        {
            left = middle + 1;
            std::cout<<temp++;
        }
        else if(q[middle]>value)
        {
            right = middle - 1;
            std::cout<<temp++;
        }
        else
            return middle;
    }
    return  -1;
}
int main()
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
    int target;
    std::cin>>target;
    std::cout<<Search(a,target)<<std::endl;
    return 0;
}