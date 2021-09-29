#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    //freopen("input.txt","r",stdin);

    cin>>t;
    long long  ans=0;
    while(t--){
        long long row,col;
        cin>>row>>col;

        if(row>=col){
           ans=(row%2==0)?row*1ll*row-col+1:(row-1)*1ll*(row-1)+col;
        }
        else if(row < col){
            ans=(col%2!=0)? col*1ll*col-row+1:(col-1)*1ll*(col-1)+row;
        }
        
        cout<<ans<<endl;

    }
}