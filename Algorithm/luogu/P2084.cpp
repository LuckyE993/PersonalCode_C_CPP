#include "iostream"
#include "string"
#include "cstring"
using namespace std;
int main(int argc, char* argv[])
{
    int m;
    string n;
    cin>>m>>n;
    int length = n.length();
    int temp=0;
    for(int i=0; i<length; i++)
    {
        if(i!=0&&n[i]!='0')
        cout<<"+";
        if(n[i]=='0')
            continue;
        cout<<n[i]<<"*"<<m<<'^'<<length-i-1;

    }
    return 0;
}