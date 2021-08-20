#include<bits/stdc++.h>

using namespace std;


int main()
{
    vector<int> st={0,200,375,550,750,950,1250,1550,1900};
    int l=400;

    int count=0;
    int cur=0;
   // last position er ager tay ashle stop korbo

    while(cur<st.size()-1)
    {
        int last=cur;
        while(cur<st.size()-1&&st[cur+1]-st[last]<=l)
                cur++;
        if(cur==last) cout<<"no"<<endl;
        if(cur<st.size()-1)
            count++;
    }
    cout<<count<<endl;
}
