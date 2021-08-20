#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k, m;
    vector<ll> a, b;
   // freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    ll tmp;
    for (int i = 0; i < n; i++)
        cin >> tmp, a.push_back(tmp);
    for (int i = 0; i < m; i++)
        cin >> tmp, b.push_back(tmp);
    
    int f=0,s=0,ans=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(f<n && s<m){
        if( abs(a[f]-b[s])<=k){
            ans++;
            f++;
            s++;
        }
        else if(a[f]>b[s]+k)
            s++;
        else 
            f++;
    }


    cout << ans << endl;
}