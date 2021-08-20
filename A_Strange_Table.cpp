#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while (t--){
     
    long long  n,m,x;
    cin>>n>>m>>x;

    long long  r=(x-1)%n+1;
    long long c=(x-1)/n+1;

    cout<< m*(r-1)+c<<endl;
    
    }
    
}