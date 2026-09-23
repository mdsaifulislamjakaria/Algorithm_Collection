#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __int128 il;

const ll N=2e2+5;
const int INF=1e9+7;
const double pi=acos(-1);

vector<int>g[N];
bool track=false;
int parent[N],vis[N],mp[N][N],total_flow=0;

void solve(int u,int s,int t,int flow){
    if(track) return;
    if(u==t){
        int x=t; total_flow+=flow; track=true;
        while(x!=s){
            mp[parent[x]][x]-=flow;
            mp[x][parent[x]]+=flow; x=parent[x];
        }
        return;
    }

    for(int v:g[u]){
        if(vis[v]==0 && mp[u][v]>0){
            vis[v]=1; parent[v]=u;
            solve(v,s,t,min(flow,mp[u][v]));
            if(track) return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[u][v]+=w;
    }

    int s=1,t=n;
    while(1){
        track=false; 
        for(int i=0;i<=n;i++) parent[i]=0,vis[i]=0;

        vis[s]=1;
        solve(s,s,t,INF);
        if(track==false) break;
    }

    cout<<total_flow<<"\n";
}
