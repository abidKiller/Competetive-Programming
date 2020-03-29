#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &grid,int i,int j)
{
    int row=grid.size();
    int col=grid[0].size();

    if(i>=row||i<0||j>=col||j<0||!grid[i][j])
        return 0;
     grid[i][j]=0;
    return dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1)+1;

}
int main()
{
    vector<vector<int> > v= {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}
                            };

    bool noIsland=false;
    int ans=INT_MIN;

    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[0].size(); j++)
        {
            if(v[i][j]==1)
            {
                noIsland=true;
                ans=max(ans,dfs(v,i,j));

            }
        }
    }
    cout<<ans<<endl;

}
