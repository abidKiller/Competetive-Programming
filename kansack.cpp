#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define Max_item 101
#define Max_weight 1001
int dp[Max_item][Max_weight];// item no row  // weight  0..cap
int cap,n;
int cs[Max_item];
int wt[Max_weight];

int knapsack(int i,int w) // wi poriman wieght taken
{
    if(i==n) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int prof1=0; // state e select korle profit
    int prof2=0; // select na korle profit


    if(w+wt[i]<=cap)
        prof1=cs[i]+knapsack(i+1,w+wt[i]);
        prof2=knapsack(i+1,w);
    dp[i][w]=max(prof1,prof2);
    return dp[i][w];


}
int main()
{
    memset(dp,-1,sizeof(dp));

    cin>>n>>cap;

    for(int i=0;i<n;i++)
        cin>>wt[i]>>cs[i];
    cout<<knapsack(0,0)<<endl; //(row,col)
}
/*
3
50
10 60
20 100
30 120
*/
