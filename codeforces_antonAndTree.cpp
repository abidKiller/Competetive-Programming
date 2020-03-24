#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g ;
vector<vector<int> > g1;
vector<bool> color;
vector<int> dp;
int n1;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
       cin>>n;

      color.push_back(false);
       for(int i=0;i<n;i++)
       {
           int tmp;
           cin>>tmp;
           if(tmp==0)
           color.push_back(false);
           else color.push_back(true);
       }



       for(int i=0;i<n-1;i++)
       {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
       }

}
/*
15
0 1 0 0 1 1 0 1 1 1 1 1 0 1 0
10 7
10 3
10 8
5 7
13 14
8 13
15 4
15 13
5 2
9 3
11 15
13 6
1 12
9 1

*/
