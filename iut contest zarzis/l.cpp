#include<bits/stdc++.h>
using namespace std;
struct data
{
  int h,x ;
}g[100001];
int s[100001];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {  int n;
       int m=0;
        cin>>n;

        double sum=0,ans,v;
        int b,h,w,d;

        for(int i=1;i<=n;i++)
        {
            cin>>b>>h>>w>>d;
            s[i]=w*d;
            g[m].h=b,g[m++].x=i;
            g[m].h=b+h,g[m++].x=-i;
            sum+=1.0*h*w*d;

        }
        cin>>v;
        if(v>sum) cout<<"OVERFLOW"<<endl;
        else
        {
            sort(g,g+m,[](const data &a,const data &b){ return a.h<b.h;});
            ans=g[0].h;
            sum=0;
            for(int i=0;i<m&&v>0;i++)
            {
                if(i>0 &&g[i].h>g[i-1].h)
                {
                    v-=sum*(g[i].h-g[i-1].h);
                    ans+=(g[i].h-g[i-1].h);
                    if(v<0)
                        ans+=v/sum;
                }
                if(g[i].x<0) sum-=s[-g[i].x];
                else sum+=s[g[i].x];

            }
            cout<<fixed<<setprecision(2)<<ans<<endl;
        }
    }
}
