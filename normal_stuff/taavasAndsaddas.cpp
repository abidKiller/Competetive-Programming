   #include<bits/stdc++.h>
using namespace std;

int main(){

    string a;

    cin>>a;

    int ans= (1<<strlen(a)) -2;
    int n= strlen(a)
    for(int i=n-1 ,int pos=0 ;i> =0,pos<n ;i--,pos++){

        if(a[i]== '7'){
            ans+=(1<<pos)
        }
    } 
}