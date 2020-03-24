#include<bits/stdc++.h>
using namespace std;

int AmodM(string s,int mod)
{
    int num=0;
    int n=s.length();
    for( int i=0;i<n;i++)
    {
        num=(num*10+(s[i]-'0'));
        num%=mod;
    }
    return num;
}

int ApowBmodM(string &a,int b,int m)
{
    unsigned int ans=AmodM(a,m);
    unsigned int mul=ans;
    for(unsigned int i=1;i<b;i++)
        ans=(ans*mul)%m;
    return ans;
}
int main()
{
    string a;
    unsigned int b,m;
    while(cin>>a)
    {
        cin>>b>>m;
        if(stoi(a)==m)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<ApowBmodM(a,b,m)<<endl;
    }

}
