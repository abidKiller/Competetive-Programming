#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string solve(string s)
{

        for(int i=0,j=0;i<s.size();i++,j++)
            dp[i][j]=1;

        for(int i=s.size()-2;i>=0;i--)
            for(int j=i+1;j<s.size();j++)
                if(s[i]==s[j])
                   {
                    dp[i][j]=2+dp[i+1][j-1];

                   }

                 else
                     dp[i][j]=max(dp[i][j-1],dp[i+1][j]);


       /* for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<s.size();j++)
                cout<<dp[i][j]<<" ";
                cout<<endl;
        }
    */
        return dp[0][s.size()-1];
}

int main()
{
    string s="abbbadda";
    //cin>>s;
    cout<<solve(s)<<endl;
}
