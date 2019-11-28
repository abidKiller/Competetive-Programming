#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int > vi;
#define pb push_back

#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))   //
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))  //


vector<int> primes; //prime numbers needed

int spf[1000005]; // all number checker array
vi pf[100005];    // in range numbers

ll a,b ;

ll solve(ll n)
{
	ll x =n;
	ll ans=1;
	priority_queue<ll> pq;

	//prime factorizing
	for(int i=0;i< pf[n-a].size() && x!=1;i++)
	{
		int count=0;
		while(x%pf[n-a][i] ==0)
		{
			x/=pf[n-a][i];
			count++;
		}
		pq.push(count+1);
		ans*=(count+1);
	}
	if(x!=1)  { pq.push(2); ans*=2;}

	ll cur=ans;
	ans=0;
   // like bfs 
	while(!pq.empty())
	{
		ans+=cur;
		ll highFreq=pq.top();
		pq.pop();
		cur/=highFreq;
		cur*=(highFreq-1);
		if(highFreq>2) pq.push(highFreq-1);

	}

	return ans;

}

int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b;

	for(int i=0;i<1000005;i++) spf[i]=-1;


   // will store smallest prime of then numbers

	for(int i=2;i<1000005;i++)
	{
		if(spf[i]==-1)
		{
			spf[i]=1;
			if(i<1000) primes.pb(i);

			for (ll j=((a-1)-(a-1)%i)+i;j<=b;j+=i)
				pf[j-a].pb(i);
		}
		for(int j=0;j<primes.size()&&primes[j]<=spf[i]&&i*primes[j]<=1000000;j++)
			spf[primes[j]*i]=primes[j];

	}
	ll total=0;

	for(ll j=a;j<=b;j++)
		total+=solve(j);

	cout<<total<<endl;

}
