class Solution {
    public:
        void dfs(vector<vector<int>>& grid, int color, int i, int j, int c, vector<vector<int>>& v, vector<vector<bool>>& visited) {
            if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size()) return;
            if(visited[i][j]) return; 
    
            visited[i][j] = true;
    
            if(grid[i][j] == c){
                if(i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1 || 
                   (j > 0 && grid[i][j-1] != c) || 
                   (j < grid[0].size() - 1 && grid[i][j+1] != c) || 
                   (i > 0 && grid[i-1][j] != c) || 
                   (i < grid.size() - 1 && grid[i+1][j] != c)) {
                    v[i][j] = color;
                }
    
                dfs(grid, color, i+1, j, c, v, visited);
                dfs(grid, color, i-1, j, c, v, visited);
                dfs(grid, color, i, j+1, c, v, visited);
                dfs(grid, color, i, j-1, c, v, visited);
            }
        }
    
        vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
            vector<vector<int>> v = grid;
            int c = grid[row][col];
            vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
            dfs(grid, color, row, col, c, v, visited);
            return v;
        }
    };
    