
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a;
    cin>>b;

    if(a.length()>b.length())
        cout<<">"<<endl;
    else if(a.length()<b.length())
        cout<<"<"<<endl;
    else
    { int n=a.length();

        for(int i=0;i<n;i++)
        {
            if(a[i]>b[i])

            {
                cout<<">"<<endl;
             return 0;
            }
            else if(a[i]<b[i])
            {
                cout<<"<"<<endl;
                return 0;
            }

        }

        cout<<"="<<endl;
    }



}
