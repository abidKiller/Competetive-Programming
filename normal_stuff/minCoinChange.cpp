#include<bits/stdc++.h>
using namespace std;

int minCoinT(vector<int >& dp,vector<int> &coins,int amount){
    if(amount==0 ) return 0;

    if(dp[amount]!=0) return dp[amount];
      dp[amount]=INT_MAX;
    for(int i=0;i<coins.size();i++){
      
        if(amount-coins[i]>=0)
            dp[amount]=min(dp[amount],minCoinT(dp,coins,amount-coins[i])+1);
    }
    return dp[amount];
}

int minCoinB(vector<int> coins,int amount){
   
    vector<int> dp(1000,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=amount;i++){
        for(int j=0;j<coins.size();j++){
            if(i-coins[j]>=0)
                dp[i]=min(dp[i-coins[j]]+1,dp[i]);
        }
    }

    return dp[amount];
}
int main(){
    vector<int> coins={1,5,7};
    vector<int> dp(1000,0);
    dp[0]=0;

    int amount=25;
    cout<<minCoinT(dp,coins,amount)<<endl;


}