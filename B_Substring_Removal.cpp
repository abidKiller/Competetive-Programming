#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     string s;
     cin>>n>>s;
     int r=0;
     int l=0;
     for(int i=0;i<n;i++)
        if(s[0]==s[i])
            l++;
        else break;
    for(int i=n-1;i>=0;i--)
        if(s[n-1]==s[i])
            r++;
        else break;
    long long ans=0;
    if(s[0]==s[n-1])
        ans=((long long )(r+1)*(l+1))% 998244353 ;
    else
        ans=(r+l+1)% 998244353 ;
    cout<<ans<<endl;
}   