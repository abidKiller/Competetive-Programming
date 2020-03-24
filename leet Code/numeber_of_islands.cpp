
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
     int numIslands(vector<vector<char> > &grid)
    {
        int row=grid.size();
        int col=grid[0].size();
        int num=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
              num+=dfs(grid,i,j);
             // cout<<grid[i][j];
             // cout<<endl;
        }
      return num;
    }
     int dfs(vector<vector<char> > &grid,int i,int j)
    {
        int row=grid.size();
        int col=grid[0].size();
        if(i>=row||j>=col||i<0||j<0 || grid[i][j]=='0') return 0;

        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        return 1;
    }
};
int main()
{
    vector<vector<char>> grid;
    grid.resize(5);
    for(int i=0;i<5;i++)
    {
        grid[i].resize(6);
        for(int j=0;j<6;j++)
         cin>>grid[i][j];
    }
    Solution s;
    cout<< s.numIslands(grid);


}
/*
111101
110000
111111
000001
111111

*/
