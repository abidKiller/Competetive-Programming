
#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
        vector<vector<int> > grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};

      int k=1;
        int n=grid.size();
        int m=grid[0].size();
        int vis[n+1][m+1];
        memset(vis,INT_MAX,sizeof(vis));

         int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

        queue<vector<int>> pack;

        pack.push({0,0,0});
        int steps=0;
        while(!pack.empty())
        {

           int s=pack.size();
           while(s--)
           {
               vector<int> temp=pack.front();
               cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<endl;
               pack.pop();
               if(temp[0]==n-1&&temp[1]==m-1) cout<<steps<<endl;

               int row=temp[0];
               int col=temp[1];

               for(auto dir:dirs)
               {
                   int r=dir[0]+row;
                   int c=dir[1]+col;

                   if(r>=0&&c>=0 &&r<=n-1&&c<=m-1)
                   {



                    int o=grid[r][c]+temp[2];

                    if(o>k||vis[r][c]<=o)continue;
                    vis[r][c]=o;
                    pack.push({r,c,o});
                   }

               }


           }
           steps++;
        }

}
