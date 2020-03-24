
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public :
    int singleNumber(vector<int> &a)
    {
        set<int> s;
        map<int,bool> l;

        for(int i=0;i<a.size();i++)
        {
            if(s.find(a[i])!=s.end()||l[a[i]])
            {
               s.erase(a[i]);
               l[a[i]]=true;
            }
            else
                s.insert(a[i]);
        }

        for(auto it=s.begin();it!=s.end();it++)
           cout<<*it<<" ";
        //cout<<s.size();
        return *s.begin();

    }
};
char *int2bin(int n) {
    // determine the number of bits needed ("sizeof" returns bytes)
    int nbits = sizeof(n) * 8;
    char *s = (char*)malloc(nbits+1);  // +1 for '\0' terminator
    s[nbits] = '\0';
    // forcing evaluation as an unsigned value prevents complications
    // with negative numbers at the left-most bit
    unsigned int u = *(unsigned int*)&n;
    int i;
    unsigned int mask = 1 << (nbits-1); // fill in values right-to-left
    for (i = 0; i < nbits; i++, mask >>= 1)
        s[i] = ((u & mask) != 0) + '0';
    return s;
}
int main()
{
    vector<int> s={4,4,3,4,5,3,10,3,5,};
  //  vector<int> m={4,7,7,10,4};
    Solution l;
      int n=10;
      cout<<int2bin(n)<<endl;
    cout<<int2bin(-10)<<endl;
   // cout<<l.singleNumber(s);
}
