
#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    int n,k;
    cin>>t;
    while(t--)
    {
     cin>>n>>k;
     string ans;
      k--;
      long long rem=2;
      for(int i=0;i<n;i++)
      {
            long long rc=n-i-1;
            long long ca;
            if(rem<=0) ca=1;
            else if(rem==1) ca=rc;
            else ca=rc*(rc-1)/2;

            if (k<ca)
               ans.push_back('a');
            else
            {
                ans.push_back('b');
                rem--;
                k-=ca;
            }


      }

 cout<<ans<<endl;

    }


}
