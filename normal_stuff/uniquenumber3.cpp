#include<iostream>
#include<vector>
using namespace std;

int findUnique(int a[],int n){
   
    vector<int> bits(64,0);
    
    for(int i=0;i<n;i++){

        int num=a[i];
        int j=0;
        while(num>0){
            bits[j++]+=(num&1);
            num=(num>>1);
        }
       
    }

    int ans=0;
    int power=1;

    for(int i=0;i<bits.size();i++){
        ans+=bits[i]%3*power;
        power=(power<<1);
    }

   return ans;
}

int main(){
    int a[]={121,222,121,222, 121,   193409   ,3234,443,3234,3234,443,443,222};
    int n=sizeof(a)/sizeof(int);
    cout<<findUnique(a,n)<<endl;


}