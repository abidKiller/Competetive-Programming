#include<bits/stdc++.h>
using namespace std;
int t;
const double pi =atan(1.0)*4.0;
double r[3];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>r[0]>>r[1]>>r[2];
        double R=(r[0]*r[1]*r[2])/(r[0]*r[1]+r[1]*r[2]+r[2]*r[0]+2.0*sqrt(r[0]*r[1]*r[2]*(r[0]+r[1]+r[2])));
        cout<<fixed<<setprecision(9)<<R<<endl;
    }
    return 0;
}
