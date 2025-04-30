class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n=rooms.size();
            unordered_set<int>vis;
            queue<int>q;
            q.push(0);
            while(!q.empty()){
                int node=q.front();
                vis.insert(node);
                q.pop();
                for(auto it:rooms[node]){
                    if(!vis.count(it)) q.push(it);
                }
            }
            if(vis.size()==n) return true;
            return false;
        }
    };