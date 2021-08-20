#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        string s;
        cin>>s;
        n=s.size();
        int i=0;
        for( i=0;i<n;i++){
            if(s[i]!='a') break;
        }
       
        if(i==n) {cout<<"NO"<<endl; continue;}
        
        string str=s;
        string str2=s;
        str.insert(i,1,'a');
        str2.insert(i+1,1,'a');
    
        bool x=false;
        for(int k=0,j=n;k<=(n+1)/2;k++,j--){
            if(str[k]!=str[n-k]) {
                cout<<"Yes"<<"\n"<<str<<endl;
                x=true;
                break;
            }
        }
        if(!x)
        cout<<"Yes"<<"\n"<<str2<<endl;
        s.clear();
        str.clear();
        str2.clear();

    }
}