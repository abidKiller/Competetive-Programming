#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10001],height,eular,first,segtree;
vector<bool > vis;
int n;


void dfs(int node,int h)
{
     vis[node]=true;
     height[node]=h;
     first[node]=eular.size();
     eular.push_back(node);
     int len=adj[node].size();
     for(int i=0;i<len;i++)
     {
         if(!vis[adj[node][i]])
         {
            dfs(adj[node][i],h+1)
            eular.push_back(node);
         }
     }

}
int query(int node,int shuru,int sesh,int u,int v)
{

}
int lca(int u,int v)
{

}

int main()
{


}

/*
7
1 2
1 3
2 3
2 4
2 5
3 6
3 7

*/
