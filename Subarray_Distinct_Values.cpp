#include<bits/stdc++.h>

using namespace std;

int check(vector<int> a,int subsets,int atleast,int k){
    int ans=0;
    
    for(int i=0;i<subsets;i++){
       
       unordered_map<int,int> m; 
       for(int j=0;j<a.size();j++){
           int f=1<<j;
           if((i&f)!=0){
               m[a[j]]++;
               cout<<a[j]<<" ";
           }
       }
       cout<<endl;
       if(m.size()>=k)
        ans++;
    }
    return ans;
}
int main(){
    int n,k;
    freopen("input.txt","r",stdin);
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int subsets=1<<n;4444
    int atleast=1<<k;
    
    cout<<check(a,subsets,atleast,k);

}