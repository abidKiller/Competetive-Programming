#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    string s,r;
    cin>>s>>r;
    vector<int> soja(m);
    vector<int> ulta(m);
    int idx=0;
  
   for(int i=0;i<n and idx<m;i++){
       if(s[i]==r[idx])
        soja[idx++]=i;  
   }
     
   idx=m-1;
   for(int i=n-1;i>=0 and idx>=0;i--){
       if(s[i]==r[idx])
        ulta[idx--]=i;  
   }
  
    
    int maxi=INT_MIN;
    for(int i=0;i<m-1;i++){
        maxi=max(maxi,ulta[i+1]-soja[i]);
    }
    cout<<maxi<<endl;

}