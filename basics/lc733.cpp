class Solution {
    public:
        void dfs(vector<vector<int>>&image,int sr,int sc,int color,int og){
            if(image[sr][sc]==color) return;
            image[sr][sc]=color;
            if(sr+1<image.size() && image[sr+1][sc]==og) dfs(image,sr+1,sc,color,og);
            if(sr-1>=0 && image[sr-1][sc]==og) dfs(image,sr-1,sc,color,og);
            if(sc+1<image[0].size() && image[sr][sc+1]==og) dfs(image,sr,sc+1,color,og);
            if(sc-1>=0 && image[sr][sc-1]==og) dfs(image,sr,sc-1,color,og);
            return;
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int og=image[sr][sc];
            dfs(image,sr,sc,color,og);
            return image;
        }
    };