#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

int nCr(int n,int r)
{
    if(n==1) return n;
    if(r==n) return 1;
    if(n==0 || r==0) return 1;
    if(dp[n][r]!=-1) return dp[n][r];

    else
    {
    dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
    return dp[n][r];
    }

}

int main()
{
    int n,r;
    cin>>n>>r;
    memset(dp,-1,sizeof(dp));
    cout<<nCr(n,r)<<endl;
}
