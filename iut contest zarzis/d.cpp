#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return (b>0)?gcd(b,a%b):a;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a[200];
    cin>>n;
    int Max=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>Max)
            Max=a[i];
    }
    int p=a[0];
    for(int i=1;i<n;i++)
        p=gcd(p,a[i]);
    int ans=Max/p-n;
    cout<<((ans&1)?"Alice\n":"Bob\n");
    return 0;

}
