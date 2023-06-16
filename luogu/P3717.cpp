#include "iostream"
#include "cmath"
using namespace std;
bool a[200][200];

int main(int argc, char* argv[])
{
    int n,m,r;
    cin>>n>>m>>r;
    int x,y;
    for(int i=0;i<m;i++) //totally m executions
    {
        cin>>x>>y;
        a[x-1][y-1] = true;
        for(int x_i = 0;x_i < n;x_i++)
        {
            for(int y_i = 0;y_i < n;y_i++)
            {
                if((x_i-x+1)*(x_i-x+1)+(y_i-y+1)*(y_i-y+1)<=r*r)
                {
                    a[x_i][y_i] = true;
                }
            }
        }
    }
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i][j])
            {
                sum++;
            }
           // cout<<a[i][j]<<" ";
        }
        //cout<<endl;

    }
    cout<<sum<<endl;
    return 0;
}



 /*
 *0 0 1 0 0
 *0 1 1 1 0
 *1 1 1 1 1
 *0 1 1 1 0
 *0 0 1 0 0
 * */