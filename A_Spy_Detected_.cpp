#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int , pair<int,int> > ans;
    for(int i=0;i<n;i++)
     {
         cin>>a[i];
         ans[a[i]] = {i,ans[a[i]].second+1};
     }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    
    for(int i=0;i<ans.size();i++)
        if(ans[a[i]].second==1)
            cout<< ans[a[i]].first+1<<endl;
    
    ans.clear();

}
int main(){
    int t;
    freopen("input.txt","r",stdin);
    cin>>t;
    while(t--){
        solve();
    }
}