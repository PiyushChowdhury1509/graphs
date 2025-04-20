//print true if it is possible to reach the goal node from source node;

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

void addEdge(int u,int v,vector<list<int>>&graph,bool undirected=true){
    graph[u].push_back(v);
    if(undirected) graph[v].push_back(u);
}

void display(vector<list<int>>&graph){
    cout<<"the graph is : "<<endl;
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto val: graph[i]){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}

bool dfs(int start,int goal,vector<list<int>>&graph,unordered_set<int>&vis){
    if(start==goal) return true;
    vis.insert(start);
    for(auto node: graph[start]){
        if(!vis.count(node)){
            int result = dfs(node,goal,graph,vis);
            if(result) return result;
        }
    }
    return false;
}

int main(){

    cout<<"enter input: ";
    int nodes,edges;
    cin>>nodes>>edges;

    vector<list<int>>graph(nodes,list<int>());

    int copyedges=edges;
    while(copyedges--){
        int u,v;
        cin>>u>>v;
        addEdge(u,v,graph,true); //true if undirected graph, false otherwise
    }

    int start,goal;
    cin>>start>>goal;
    unordered_set<int>vis;
    bool ans=dfs(start,goal,graph,vis);
    if(ans) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}