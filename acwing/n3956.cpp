#include "iostream"
using namespace std;
int arr[1000010];
int b[1000010];
int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int  sum=0,answer=0;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        b[i] = arr[i]+b[i-1];
        sum += arr[i];
    }
    if(sum%3)
    {
        cout<<"0";
    } else
    {
        int temp = sum/3;
        for(int i=0;i<n;i++)
        {
            if(b[i]==temp)
            {

            }
        }
    }

    return 0;
}
