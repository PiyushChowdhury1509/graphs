//shortest path from source to goal

#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

int bfs(vector<list<int>>&graph,int source,int goal){
    vector<int>dist(graph.size(),-1);
    queue<int>q;
    unordered_set<int>st;
    dist[source]=0;
    q.push(source);
    st.insert(source);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==goal) return dist[goal];
        for(auto i:graph[node]){
            if(!st.count(i)){
                q.push(i);
                st.insert(i);
                dist[i]=1+dist[node];
            }
        }
    }
    return -1;
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
        addEdge(u,v,graph,true); 
    }

    int source,goal;
    cin>>source>>goal;
    int ans=bfs(graph,source,goal);
    cout<<ans;

    return 0;
}