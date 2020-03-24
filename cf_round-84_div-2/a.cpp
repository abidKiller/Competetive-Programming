
#include<bits/stdc++.h>
using namespace std;

int oddSum(int n)
{
    int sum=0;
    for(int i=1;i<n;i+=2)
        sum+=i;

    return sum;
}

int main()
{


    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

            for(int i=0;i<=n;i++)
            {
                if(oddSum(i)==n)
                {
                    cout<<"YES"<<endl;
                    break;
                }

            }
        cout<<"NO"<<endl;


    }
}
