
#include<bits/stdc++.h>
using namespace std;
vector<double> calc(double x,double y)
    {
        return vector<double>{x+y,x-y,y-x,x/y,y/x,x*y};
    }
bool helper(vector<double> &v)
 {
     if(v.size()==1) return abs(24-v[0])<0.001;

     for(int i=0;i<v.size();i++)
     {
        for(int j=i+1;j<v.size();j++)
        {
            vector<double> temp(v.size()-1);

            for(int k=0,idx=0;k<v.size();k++)
            {
                if(k!=i&&k!=j)
                    temp[idx++]=v[k];
            }
            for(auto d:calc(v[i],v[j]))
            {
                temp[temp.size()-1]=d;
                if(helper(temp)) return true;
            }

        }

     }
     return false;
 }



bool judgePoint24(vector<int>& nums) {
       vector<double> v(nums.begin(),nums.end());
        return helper(v);
}

int main()
{

     vector<int> v={1,2,3,4};
    // vector<vector<int>> s={{1,4,},{4,6}};


    cout<<judgePoint24(v)<<endl;
}
