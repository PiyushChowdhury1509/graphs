//check if path exist from goal to end

class Solution {
    public:
        bool dfs(int source,int destination,vector<list<int>>&graph,unordered_set<int>&vis){
            if(source==destination) return true;
            vis.insert(source);
            for(auto node:graph[source]){
                if(!vis.count(node)){
                    if(dfs(node,destination,graph,vis)) return true;
                }
            }
            return false;
        }
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            vector<list<int>>graph(n,list<int>());
            for(auto edge: edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            unordered_set<int>vis;
            return dfs(source,destination,graph,vis);
        }
    };