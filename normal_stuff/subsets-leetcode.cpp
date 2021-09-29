#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
 vector<int> seqs(vector<int> & nums,int n ){
        vector<int > holder;
        int i=0;
        while(n>0) {
            if(n&1)  {
                holder.push_back(nums[i]);
                cout<<nums[i]<<" "; 
                }
            i++;
            n=n>>1;
        }
        cout<<""<<endl;
        return holder;    
    }
    
    vector<vector< int> > subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int n = nums.size();
        int range = (1<<n);
        
        for(int i=0;i<range;i++)
         ans.push_back(seqs(nums,i));
        
        return ans;
    }
int main(){

    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(5);

    subsets(a);

    return 0;
}