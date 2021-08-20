#include<bits/stdtr1c++.h>
using namespace std;
vector<string> st={"0","1"};
void recursive(int n){
    if(n==1) { return ;}
    
    recursive(n-1);
    
    vector<string> tmp;
    for(int i=0;i<st.size();i++){
        tmp.push_back(st[i]+'0');
    }
    for(int i=st.size()-1;i>=0;i--){
        tmp.push_back(st[i]+'1');
    }
    st=tmp;

}
int main(){
    int n;
   // freopen("input.txt","r",stdin);
    cin>>n;

    recursive(n);
    for(int i=0;i<st.size();i++){
        reverse(st[i].begin(),st[i].end());
        cout<<st[i]<<endl;
    }

}