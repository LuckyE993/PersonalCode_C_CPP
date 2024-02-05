#include "iostream"
using namespace std;
int main()
{
    int k,m,n;
    cin>>k>>m>>n;
    bool flag=0;
    int cost,hurt;
    for(int i=1;i<=m;i++)
    {
        cin>>cost>>hurt;
        if((cost==0&&hurt)||(cost&&k/cost*hurt>=n))
        {
            flag=1;
            cout<<i<<" ";
        }
    }
    if(!flag)
        cout<<"-1";
    return 0;
}