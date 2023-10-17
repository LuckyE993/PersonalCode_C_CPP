#include "iostream"
using namespace std;
int array[1000010];
int b[1000010];
int main(int argc, char* argv[])
{
    int n,m;
    int l,r;
    cin >> n ;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>array[i];
        b[i] = b[i-1]+array[i];
    }

    while(m--)
    {
        cin>>l>>r;
        cout<<b[r]-b[l-1]<<endl;
    }
    return 0;
}

