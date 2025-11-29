#include<bits/stdc++.h>
using namespace std;
void depthFirstSearch(int node,vector<int> adj[],int vis[],vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            depthFirstSearch(it,adj,vis,ls);
        }
    }
}
vector<int> dfs(int n,vector<int> adj[]){
    int vis[n+1]={0};
    vector<int> ls;
    depthFirstSearch(1,adj,vis,ls);
    return ls;
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
    vector<int> res=dfs(n,adj);
    for(auto c:res) cout<<c<<" ";
    return 0;
}