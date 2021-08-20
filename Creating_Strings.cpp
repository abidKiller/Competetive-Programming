#include<bits/stdc++.h>
using namespace std;
int ans=0;
vector<string> vans;
//distict 
/*
void permute(string a,string b){
    if(a.size()==0) {ans++,vans.push_back(b);return ;}
    bool pos[26]={false};
    for(int i=0;i<a.size();i++){
        char c=a[i];
        string a1=a.substr(0,i)+a.substr(i+1,a.size());
        if(!pos[c-'a'])
            permute(a1,b+c);
        pos[c-'a']=true;
    }
}*/
bool check(string s,int l,int idx){
    for(int i=l;i<idx;i++)
        if(s[i]==s[idx]) return false;
    return true;
}
void permute(string s,int l,int r){
    if(l==r) {ans++;return; vans.push_back(s);}
   
    for(int i=l;i<=r;i++){
        
        if(check(s,l,i)){
            swap(s[l],s[i]);
            permute(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}
int main(){
    string s;
    freopen("input.txt","r",stdin);
    cin>>s;
    sort(s.begin(),s.end());
    permute(s,0,s.size()-1);
    cout<<ans<<endl;
    for(auto it:vans){
        cout<<it<<endl; 
    }   
}