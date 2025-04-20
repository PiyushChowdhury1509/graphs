//all paths from source to goal

class Solution {
    public:
        void dfs(vector<vector<int>>& graph,int start,int goal,vector<vector<int>>& ans,vector<int>&temp,unordered_set<int>& vis){
            if(start==goal){
                temp.push_back(goal);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
            temp.push_back(start);
            vis.insert(start);
            for(auto node: graph[start]){
                if(!vis.count(node)) dfs(graph,node,goal,ans,temp,vis);
            }
            temp.pop_back();
            vis.erase(start);
        }
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            int n=graph.size();
            vector<vector<int>>ans;
            vector<int>temp;
            unordered_set<int>vis;
            dfs(graph,0,n-1,ans,temp,vis);
            return ans;
        }
    };