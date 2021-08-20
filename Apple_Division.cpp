#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int n;
    //freopen("input.txt","r",stdin);
    cin>>n;
    vector<ll> v(n);
    ll sum=0; 
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int mask=1<<n;
    ll mini=INT_MAX;
    for(int i=0;i<mask;i++){
        ll subsum=0;
        for(int j=0;j<n;j++){
            int f=1<<j;
            if(f&i) subsum+=v[j];
        }
        mini=min(mini,abs(sum-2*subsum));

    }
    cout<<mini<<endl;
}