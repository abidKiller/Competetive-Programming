#include<bits/stdc++.h>
using namespace std;
string notes[]={"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};
int getIdx(string &s)
{
    for(int i=0;i<12;i++)
        if(notes[i]==s)
            return i;
    return 0;
}
string check(int idx1,int idx2,int idx3)
{
    int f,s,t;
    if(idx2<idx1)
        f=idx2+12-idx1;
    else
        f=idx2-idx1;
    if(idx3<idx2)
        s=idx3+12-idx2;
    else
        s=idx3-idx2;
    if(f==4 && s==3)
        return "major";
    else if(f==3&&s==4)
        return "minor";
    else
        return "strange";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int idx1,idx2,idx3;
    string s1,s2,s3;
    string s[6];
    cin>>s1>>s2>>s3;
    idx1=getIdx(s1);
    idx2=getIdx(s2);
    idx3=getIdx(s3);

    s[0]=check(idx1,idx2,idx3);
    s[1]=check(idx1,idx3,idx2);
    s[2]=check(idx2,idx1,idx3);
    s[3]=check(idx2,idx3,idx1);
    s[4]=check(idx3,idx1,idx2);
    s[5]=check(idx3,idx2,idx1);

    for(int i=0;i<6;i++)
        if(s[i]=="major"||s[i]=="minor")
            {
                cout<<s[i]<<endl;
                return 0;
            }
    cout<<"strange"<<endl;
    return 0;
}
