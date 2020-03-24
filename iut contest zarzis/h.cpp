#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,p1,p2,p3,t1,t2;
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    long long total=0,prev=-1;
    for(int i=0;i<n;i++)
    {
        int start,finish;
        cin>>start>>finish;
        if(prev<0) prev=start;
        total+=p1*(finish-start);
        int timeIdle=start-prev;
        if(timeIdle>t1+t2)
        {
            total+=(timeIdle-t1-t2)*p3;
            timeIdle=t1+t2;

        }
        if(timeIdle>t1)
        {
            total+=(timeIdle-t1)*p2;
            timeIdle=t1;
        }

        total+=timeIdle*p1;
        prev=finish;
    }
    cout<<total<<endl;
    return 0;
}
