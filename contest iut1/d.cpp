#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x1,x2,y1,y2,r1,r2;
    int d;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

    if(d==(r1+r2)*(r1+r2) || d==abs(r1-r2)*abs(r1-r2) )
        cout<<"1"<<endl;
    else if(r1==r2 && x1==x2 && y1==y2)
        cout<<"-1"<<endl;
    else if(d< r1 * r2)
        cout<<"2"<<endl;
    else
        cout<<"0"<<endl;


}
