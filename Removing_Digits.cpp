#include<bits/stdc++.h>
using namespace std;
vector<int> dp(10000007,INT_MAX);
int digRemove(int n){
    if(n==0) return 0;
    if(n<0) return INT_MAX;
    if(dp[n]!=INT_MAX) return dp[n];
    int tmp=n;
        
        while(tmp){
        int dig =tmp%10;
        if(dig!=0 && digRemove(n-tmp%10)!=INT_MAX)
            dp[n]=min(dp[n],digRemove(n-dig)+1);
        tmp/=10;
        }
    return dp[n];
}  
int main(){
    int n;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   #endif
    cin>>n; // n=103330
    

    cout<<digRemove(n)<<endl;

}