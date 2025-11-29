#include<bits/stdc++.h>
using namespace std;
vector<int> breadthFirstSearch(int n,vector<int> adj[]){
    vector<int> vis(n+1,0); // visited array 
    vis[1]=1; // initial node 
    queue<int> q;
    q.push(1);
    vector<int> bfs; // to store bfs traversal 
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node]){ // traverssing over neighbours of that node  
            if(!vis[it])
            vis[it]=1;
            q.push(it);
        }
    }
    return bfs;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res=breadthFirstSearch(n,adj);
    cout<<"Breadth First Search: "<<endl;
    for(auto c:res){
        cout<<c<<" ";
    }
    return 0;
}