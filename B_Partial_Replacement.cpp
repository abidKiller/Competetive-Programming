#include<bits/stdc++.h>
using namespace std;

void solve(){

    

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
    string s;
    cin>>n>>k>>s;
    int i=s.find_first_of('*');
    int ans=1;
     while(true){
         int j=min(i+k,n-1);

         for(;j>i&&s[j]=='.';j--);
         if(i==j) break;

         ans++;
         i=j;

     }
     cout<<ans<<endl;
    }

}