class Solution {
    public:
        void dfs(vector<vector<int>>&graph,int node,unordered_set<int>&st){
            st.insert(node);
            for(auto i:graph[node]){
                if(!st.count(i)) dfs(graph,i,st);
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n=isConnected.size();
            vector<vector<int>>graph(n,vector<int>());
            for(int i=0;i<n;i++){
                for(int j=0;j<isConnected[0].size();j++){
                    if(isConnected[i][j]){
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
            int ans=0;
            unordered_set<int>st;
            for(int i=0;i<graph.size();i++){
                if(!st.count(i)){
                    ans++;
                    dfs(graph,i,st);
                }
            }
            return ans;
        }
    };