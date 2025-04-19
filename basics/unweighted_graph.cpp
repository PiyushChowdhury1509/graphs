#include<iostream>
#include<vector>
#include<list>
using namespace std;

void addEdge(int u,int v,vector<list<int>>&graph,bool undirected){
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

    display(graph);

    return 0;
}