#include<bits/stdc++.h>
using namespace std;


int lcs(string a,string b){
    vector<vector<int > > dp(a.size(),vector<int>(b.size()));

    int mini=INT_MIN;

    for(int i=0;i<a.size();i++){
        
        for(int j=0;j<b.size();j++){
            dp[i][j]=0;
            if(a[i]==b[j]&&i-1>=0&&j-1>=0)
                dp[i][j]=dp[i-1][j-1]+1;
            else if (a[i]==b[j]) dp[i][j]=1;
            mini=max(dp[i][j],mini);
        }
    }
    return mini;
}

void solve(){
    string a,b;
    cin>>a>>b;
    int match=lcs(a,b);
    cout<<a.size()+b.size()-2*match<<endl;
}
int main(){

    int t;
    cin>>t;
    while(t--){
        solve();

    }
}