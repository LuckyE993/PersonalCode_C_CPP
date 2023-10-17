#include "iostream"
using namespace std;
struct boom
{
    int boom_value=0;
    int last_boom=0;
};
struct boom a[105][105];//数组从1开始计数

int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int p_x1,p_y1,p_x2,p_y2;
    for(int times=1;times<=x;times++)
    {
        cin>>p_x1>>p_y1>>p_x2>>p_y2;
        for(int i=p_x1;i<=p_x2;i++)
            for(int j=p_y1;j<=p_y2;j++)
            {
                a[i][j].boom_value+=1;
                a[i][j].last_boom = times;
            }
    }

    while(y--)
    {
        cin>>p_x1>>p_y1;
        if(a[p_x1][p_y1].boom_value)
        {
            cout<<"Y"<<" "<<a[p_x1][p_y1].boom_value<<" "<<a[p_x1][p_y1].last_boom<<endl;
        }
        else
            cout<<"N"<<endl;
    }
    return 0;
}
