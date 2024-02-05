#include "iostream"
using namespace std;

int main()
{
    int k,x,y;
    int score_x,score_y;
    score_x = score_y = 0;
    cin>>k;
    while(k--)
    {
        cin>>x>>y;//
        if(x==20&&(y==5||y==10))//意外情况：小王说20，小明为5/10
        {
            score_y+=10;
            continue;
        }
        if(y==20&&(x==5||x==10))//意外情况：小明说20，小王为5/10
        {
            score_x+=10;
            continue;
        }
        if(x>y)
            score_x+=(x-y);
        else
            score_y+=(y-x);
    }
    cout<<score_x<<" "<<score_y<<endl;
    return 0;
}