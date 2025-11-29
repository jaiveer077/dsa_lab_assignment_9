#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n,m;
    if(!(cin>>n>>m))return 0;
    vector<vector<pair<int,ll>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v; ll w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    const ll INF = (1LL<<60);
    vector<ll> key(n,INF);
    vector<int> parent(n,-1);
    vector<char> inMST(n,false);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    key[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto [k,u]=pq.top(); pq.pop();
        if(inMST[u]) continue;
        inMST[u]=1;
        for(auto &e:adj[u]){
            int v=e.first; ll w=e.second;
            if(!inMST[v] && w<key[v]){
                key[v]=w;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }
    ll total=0;
    for(int i=0;i<n;i++){
        if(key[i]==INF){
            cerr<<"Graph is not connected; MST does not exist\n";
            return 0;
        }
        total+=key[i];
    }
    cout<<"Total MST weight: "<<total<<"\n";
    cout<<"Edges in MST (u v weight):\n";
    for(int v=0;v<n;v++){
        if(parent[v]!=-1){
            cout<<parent[v]<<" "<<v<<" "<<key[v]<<"\n";
        }
    }
    return 0;
}