
#include<bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;
    cin>>t;
    long long k=1;
    while(t--)
    {
        long long dp[10001];
        dp[0]=0;
        long long n;
        cin>>n;
        if(n==0)
        {
            cout<<"Case "<<k++<<": "<<0<<endl;
            continue;
        }

        if(n==1)
        {
            long long x;
            cin>>x;
            cout<<"Case "<<k++<<": "<<x<<endl;
            continue;
        }

        cin>>dp[1]>>dp[2];
        dp[2]=max(dp[1],dp[2]);
        for(int i=3;i<=n;i++)
        {
            long long x;
            cin>>x;
            dp[i]=max(x+dp[i-2],dp[i-1]);
        }
        cout<<"Case "<<k++<<": "<<dp[n]<<endl;
    }

    return 0;
}
