#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    //freopen("input.txt","r",stdin);
    cin>>s;
    int maxi=1;
    int count=1;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]){
            count++;
            maxi=max(count,maxi);
        }
            
        else count=1;
    }
    cout<<maxi<<endl;
}