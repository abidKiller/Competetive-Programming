#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
   // freopen("input.txt","r",stdin);
    cin>>n>>x;
    vector<int> v;
    int tmp;
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        if(m.count(x-v[i])){
            cout<<m[x-v[i]]<<" "<<i+1<<endl;
            return 0;
        }
        m[v[i]]=i+1;
    }
    cout<<"IMPOSSIBLE"<<endl;
    
}