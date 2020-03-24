#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int> v[N],s;
int sq,depth[N];
bool marked[N];
//int ar[10];

void dfs(int node)
{
    s.push_back(node);
    depth[node]=s.size();
    for(int u:v[node])
    {
        if(!depth[u])
            dfs(u);
        else if(depth[node]-depth[u]+1>=sq)
        {
            printf("2\n%d\n",depth[node]-depth[u]+1);
            for(int i=depth[u]-1;i<depth[node];i++)
                printf("%d",s[i]);
            exit(0);
       }
    }


}

int main()
{
    vector<vector<int>> ls(3,vector<int> (3));

     int n,m;
     scanf("%d%d",&n,&m);
     while(sq*sq<n)
        sq++;
    cout<<sq<<endl;
  //  vector<vector<int>> a(101);
 // int ar[10][10];//={0};
        for(int i=0;i<3;i++)
        {

          for(int j=0;j<3;j++)
            printf("%d",ls[i][j]);
            printf("\n");
        }
     while(m--)
     {
         int a,b;
         scanf("%d%d",&a,&b);
         v[a].push_back(b);
         v[b].push_back(a);

     }
     dfs(1);
     printf("1\n");
     for(int i=1;sq;i++)
     {
        if(!marked[i])
        {
            printf("%d ",i);
            sq--;
        }
     }
}
