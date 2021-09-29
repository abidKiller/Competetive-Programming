#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<long long int> dp(100005);

void solve(){
    int n;
    cin>>n;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=100001;i++)
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])% mod;
    cout<<dp[n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int t;
    cin>>t;
    
    
    while(t--){
        solve();  
    }
}