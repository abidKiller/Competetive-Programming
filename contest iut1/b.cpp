
#include<bits/stdc++.h>
using namespace std;

int main()
{


    int a[10001],sum,avg,l,m,n,o,p;
    int ans;
    while(cin>>n)
    {
        sum=0;
        ans=0;
      if(n==-1)
        return 0;
      else
      {
        for(int i=0;i<n;i++)
        {
             cin>>a[i];
             sum+=a[i];
        }
        if(sum%n!=0)
        {
            cout<<"-1"<<endl;
            continue;
        }

        avg=sum/n;
        for(int i=0;i<n;i++)
        {
            if(a[i]<avg)
                ans+=(avg-a[i]);
        }
        cout<<ans<<endl;
      }
    }

}
