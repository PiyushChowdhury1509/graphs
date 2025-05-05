class Solution {
    public:
        void dfs(vector<vector<int>>& grid,int i,int j,int c,int color,vector<vector<int>>& vis,vector<vector<int>>& v){
            if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0) return;
            if(vis[i][j]) return;
            if(grid[i][j]==c){
                vis[i][j]=1;
                if(i==grid.size()-1 || j==grid[0].size()-1 || i==0 || j==0 ||
                (i-1>=0 && grid[i-1][j]!=c) ||
                (i+1<grid.size() && grid[i+1][j]!=c) ||
                (j-1>=0 && grid[i][j-1]!=c) ||
                (j+1<grid[0].size() && grid[i][j+1]!=c)
                ){
                    v[i][j]=color;
                }
                dfs(grid,i-1,j,c,color,vis,v);
                dfs(grid,i+1,j,c,color,vis,v);
                dfs(grid,i,j-1,c,color,vis,v);
                dfs(grid,i,j+1,c,color,vis,v);
            }
        }
    
        vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
            int c=grid[row][col];
            vector<vector<int>>v=grid;
            vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
            dfs(grid,row,col,c,color,vis,v);
            return v;
        }
    };