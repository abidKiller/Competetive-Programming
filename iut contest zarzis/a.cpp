#include<stdio.h>


long long sol(long long num)
{
    long long ans=1,res;
    int neg=0;
    if(num<0)
    {
        neg=1;
        num*=-1;
    }
    for(int i=2;i*i<=num;i++)
    {
        if(num%i) continue;
        long long temp=num;
        res=0;
        while(temp%i==0)
        {
            temp/=i;
            res++;
        }
        if(temp==1)
            if(!neg||res%2)return res;
    }
    return 1;
}
int main()
{

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        long long  num;
        scanf("%lld",&num);
        printf("Case %d: %lld\n",i,sol(num));

    }
    return 0;
}
