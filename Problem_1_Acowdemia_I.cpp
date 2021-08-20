#include<bits/stdc++.h>
using namespace std;
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)

int main(){
    int n,l;
    #ifndef ONLINE_JUDGE  
   // freopen("input.txt","r",stdin);
    #endif
    
    cin>>n>>l;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
        cin>>ar[i];

    sort(ar.rbegin(),ar.rend());
    int h=n;
    
    while( h>0 and ar[h-1]<h ) h--;
    if(h!=n)
    for(int j=h;j>-1 and l ;l--,j--)
        ar[j]++;
    sort(ar.rbegin(),ar.rend());
     h=n;
    while( h>0 and ar[h-1]<h ) h--;

    cout<<h<<endl;
} 