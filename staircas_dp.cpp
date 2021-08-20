#include<bits/stdc++.h>

using namespace std;
int countWays(int n,int m)
{
    int dp[n];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=m&&i-j>=0;j++)
            dp[i]+=dp[i-j];
    }
        return dp[n];
}
int main()
{
    int n,m;

    cin>>n>>m;

    cout<<countWays(n,m)<<endl;
}
