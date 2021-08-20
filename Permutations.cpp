#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
   // freopen("input.txt","r",stdin);

    cin>>n;
    if(n==1) cout<<"1"<<endl;
    else if(n<4){ cout<<"NO SOLUTION"<<endl;return 0;}
    int mid = n/2;
    int mid1=mid-1;
    int mid12=mid1-1;
    int mid2=mid+1;
    while(mid<=n) {
        cout<<mid<<" ";
        mid+=2;
    }
    while(mid1>0){
        cout<<mid1<<" ";
        mid1-=2;
    }
    
    while(mid2<=n) {
        cout<<mid2<<" ";
        mid2+=2;
    }
    while(mid12>0) {
        cout<<mid12<<" ";
        mid12-=2;
    }

} 