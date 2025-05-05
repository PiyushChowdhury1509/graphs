#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        void dfs(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&vis){
            if(i<0 || j<0 || i==grid.size() || j==grid[0].size()) return;
            if(vis[i][j]) return;
            vis[i][j]=1;
            if(i>0 && grid[i-1][j]=='1') dfs(grid,i-1,j,vis);
            if(j>0 && grid[i][j-1]=='1') dfs(grid,i,j-1,vis);
            if(i<grid.size()-1 && grid[i+1][j]=='1') dfs(grid,i+1,j,vis);
            if(j<grid[0].size()-1 && grid[i][j+1]=='1') dfs(grid,i,j+1,vis);
        }
        int numIslands(vector<vector<char>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>>vis(m,vector<int>(n,0));
            int ans=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!vis[i][j] && grid[i][j]=='1'){
                        ans++;
                        dfs(grid,i,j,vis);
                    }
                }
            }
            return ans;
        }
    };