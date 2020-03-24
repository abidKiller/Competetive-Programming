
#include<bits/stdc++.h>
using namespace std;
bool check(string s,string a,string b)
{
    bool flag=false,next=false;
    long long k=0;
    long long tsz=a.size();
    long long sz=s.size();
    for(int i=0;i<sz;i++)
    {
        if(s[i]==a[0])
        {
            if(i+tsz>=sz)
                break;
            else
            {
                for(int j=0;j<tsz;j++)
                {
                    if(s[i+j]!=a[j])
                        break;
                    if(j+1==tsz)
                    {
                        k=i+j;
                        next=true;
                        break;
                    }
                }
            }
        }
        if(next)
            break;
    }
    tsz=b.size();
    if(next)
    {
        for(long long i=k+1;i<sz;i++ )
        {
            if(s[i]==b[0])
            {
                if(i+tsz>sz)
                    break;
                else
                {
                    for(int j=0;j<tsz;j++)
                    {
                        if(s[i+j]!=b[j])
                            break;
                        if(j+1==tsz)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
            }
            if(flag)
                break;
        }
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s,a,b;
    cin>>s>>a>>b;
    bool forwar=check(s,a,b);
    reverse(s.begin(),s.end());
    bool backward=check(s,a,b);
    if(forwar &&backward)
        cout<<"both"<<endl;
    else if(forwar)
         cout<<"forward"<<endl;
    else if (backward)
        cout<<"backward"<<endl;
    else
        cout<<"fantasy"<<endl;
    return 0;
}
