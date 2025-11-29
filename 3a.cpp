#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
public:
    vector<int> size,parent;
public:
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUpar(int node){
        if(node==parent[node])
        return node;
        return parent[node]=findUpar(parent[node]); // path compression 
    }
    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        } else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int spanningTree(int V,vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            int node=i;
            int adjNode=it[0];
            int wt=it[1];
            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    int mstWt=0;
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUpar(u)!=ds.findUpar(v)){
            mstWt+=wt;
            ds.unionBySize(u,v);
        }
    }
    return mstWt;
}
int main(){
    int V=5; // number of nodes/vertices 
    vector<vector<int>> edges={{0,1,2},{0,2,1},{1,2,1},{2,3,2},{3,4,1},{4,2,2}};
    vector<vector<int>> adj[V]; // creating an array of vector of vector-> adjacency list 
    for(auto it:edges){
        vector<int> temp(2);
        temp[0]=it[1];
        temp[1]=it[2];
        adj[it[0]].push_back(temp);
        temp[0]=it[0];
        temp[1]=it[2];
        adj[it[1]].push_back(temp);
    } 
    int mst=spanningTree(V,adj);
    cout<<"The sum of the weights of the mst is "<<mst<<endl;
    return 0;
}