#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);
const ll INF=1e18;

void shortestPathBB(int src,int dest,int n,vector<vector<pair<ll,ll>>>&adj){
    ll minCost=INF;
    vector<int>bestPath;

    priority_queue<tuple<ll,int,vector<int>>,vector<tuple<ll,int,vector<int>>>,greater<tuple<ll,int,vector<int>>>>pq;
    pq.push({0,src,{src}});

    while(!pq.empty()){
        auto [c,u,path]=pq.top();
        pq.pop();

        if(c>=minCost) continue;

        if(u==dest){
            minCost=c;
            bestPath=path;
            continue; 
        }

        for(auto [v,w]:adj[u]){
            bool visited=false;
            for(int node:path){
                if(node==v){
                    visited=true;
                    break;
                }
            }

            if(!visited){
                ll nextCost=c+w;
                if(nextCost<minCost){
                    vector<int>nextPath=path;
                    nextPath.push_back(v);
                    pq.push({nextCost,v,nextPath});
                }
            }
        }
    }

    if(minCost==INF){
        cout<<"-1\n";
    }else{
        cout<<minCost<<"\n";
        for(int node:bestPath) cout<<node<<" ";
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n+1);

    for(int i=0;i<m;i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int src,dest; cin>>src>>dest;
    shortestPathBB(src,dest,n,adj);
}