#include<bits/stdc++.h>

using namespace std;

double getApproxRatio(double ab,double ac, double bc,double ad)
{
      double abc,ade;
      double s1,s2;
      double ae,de;
       ae=(ad*ac)/ab;
       de=(bc*ad)/ab;
       s1=(ab+ac+bc)/2.0;
       s2=(ad+de+ae)/2.0;

       abc=sqrt(s1*(s1-ab)*(s1-bc)*(s1-ac));
       ade=sqrt(s2*(s2-ad)*(s2-de)*(s2-ae));
       double dbce=abc-ade;
       dbce=ade/dbce;
       return dbce;

}

double getAns(double ab,double ac, double bc,double rat)
{
  double ad;
  double f=0.0;
  double e=ab;
  double mid;
  for(int i=0;i<100;i++)
  {
    mid=(e+f)/2.0;
    ad=mid;

    if(getApproxRatio(ab,ac,bc,ad)<rat)
      f=mid;
    else
      e=mid;

  }
    return ad;

}
int main()
{

  int ts,cn;
   // ios_base:: sync_with_stdio(false);
    cin>>ts;
    double ans;
    double ab,ac,bc,rat;
  for(cn=1;cn<=ts;cn++)
  {
    //double ab,ac,bc,rat;
    cin>>ab>>ac>>bc>>rat;

    ans=getAns(ab,ac,bc,rat);

    cout<<"Case "<<cn<<": "<<fixed<<setprecision(6)<<ans<<endl;
    //printf("Case %d: \n",cn,ans);
  }


}
