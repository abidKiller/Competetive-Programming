#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll> > st;
inline gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
void preCompute(vector<ll> &ar) //range minimum
{

    int n=ar.size();
    int k=log2(ar.size())+1;
     st.resize(n+1,vector<ll> (k+1,0));

    for(int i=0;i<n;i++)
        st[i][0]=ar[i];
    for(int j=1;j<k;j++)
        for(int i=0;i+(1<<j)<=n;i++)
               st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);


   //cout<<st.size()<<" "<<st[0].size()<<endl;


}

ll query(int L,int R)
{
    int j = log2(R-L+1);

     return gcd(st[L][j],st[R-(1<<j)+1][j]);
}
ll solve(ll x,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
           if(x==query(i,j))
             ans++;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> a;
    int n,m,l,r;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)
            cin>>a[i];
     preCompute(a);
    cin>>m;
    ll ans[m]={0};
    for(int i=0;i<m;i++)
    {
        int q;
        cin>>q;
        cout<<solve(q,n)<<endl;
    }

}
