#include<bits/stdc++.h>

using namespace std;

int minSteps(int n,vector<int> dp){
      if(n==1) return 0;
      if(dp[n]!=0){
          return dp[n];
      }

      int op1,op2,op3;

      op1=op2=op3=INT_MAX;

      if(n%3==0)
        op1=minSteps(n/3,dp)+1;
      if(n%2==0)
        op2=minSteps(n/2,dp)+1;

      op3=minSteps(n-1,dp)+1;
      
      return dp[n]=min(op1,min(op2,op3));
}

int minStepsIter(int n){
  int dp[n+1]={0};
  
  for(int i=2;i<=n;i++){
    dp[i]= INT_MAX;
     if(i%3==0)dp[i]=dp[i/3]+1;
     if(i%2==0) dp[i]=min(dp[i],dp[i/2]+1);
     dp[i]=min(dp[i],dp[i-1]+1);
     cout<<dp[i]<<endl;
  }
  return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n,0);
    
    
    cout<<minStepsIter(n)<<endl;


    return 0;

}