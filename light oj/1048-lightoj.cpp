#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef struct pos pos;
struct pos
{
	ll x,y;

	bool operator<(const pos &a)
	{
		if (a.x==x) return y<a.y;
		else return x<a.x;
	}
}

double getAngle(const pos &a,const pos &b,const pos &c)
{

    double ab=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    double bc=sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y));
    double ca=sqrt((c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y));

     return acos((ab*ab+bc*bc-ca*ca)/(2*ab*bc))/acos(-1.0)*180;
}

ll compare(const pos &a,const pos& b, const pos &c)
{
   return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(b.x-a.x)<=0; //true means right turn;
}

vector<pos> hull(vector<pos>& p)
{
  int n=p.size();
  int k=0;
  vecto<pos> h;
  sort(p.begin(),p.end());

  for(int i=0;i<n;i++){
  	while(k>=2&&compare(h[k-2],h[k-1],p[i])) k--;
   h[k++]=p[i];
   }

   for(int i=n-2,t=k+1;i>=0;i-- )
   {
   	while(k>=t&&compare(h[k-2],h[k-1],p[i]))k--;
   	h[k++]=p[i];
   }


}

int main()
{
    int test;

   ios_base:sync_stdio(false);
   cin.tie(NULL);

   for(int i=0;i<test;i++)
   {
   	 vector<pos> points;
   	 int n;
   	 pos in;
   	 cin>>n;
   	 for(int j=0;j<n;j++)
   	 {
   	 	cin>>in.x>>in.x;
   	 	points.push_back(in);
   	 }

   	 if(n<3)
   	 {
   	 	cout<<"Case "<<i<<":"<<0<<endl;
   	 }
   	 else
   	 {
   	 	vector<pos> points=hull(points);
   	 	int sz=points.size();

   	 	if(sz==0) {cout<<"Case "<<":"<<0<<endl;continue;}

   	 	double minAngle=getAngle(points[sz-1],points[0],points[1]);

   	 	for(int j=0;j<sz-1;j++)
   	 	{
   	 		minAngle=min(minAngle,getAngle(points[j-1],points[j],points[j+1]));

   	 	}

   	 	cout<<"Case "<<i<<":"<<min<<endll;

   	 }


    }

}