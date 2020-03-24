#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{

   int n,a,b,c,d,i,j;
   scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);

   int arr[n+1];
   for( i=1;i<=n;i++)
    arr[i]=i;
   for( i=a, j=b;i<=(a+b)/2;i++,j--)
       swap(arr[i],arr[j]);
   for( i=c,j=d;i<=(c+d)/2;i++,j--)
      swap(arr[i],arr[j]);

   for( i=1;i<=n;i++)
    printf("%d ",arr[i]);


}
