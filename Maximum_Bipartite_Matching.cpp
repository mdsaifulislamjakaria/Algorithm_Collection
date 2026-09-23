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
    map<int,int>left,right;
    for(int i=0;i<m;i++){
        int u,v,w=1; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[u][v]=1;

        if(left[u]==0){
            g[0].push_back(u);
            g[u].push_back(0);
            mp[0][u]=1; left[u]=1;
        }

        if(right[v]==0){
            g[v].push_back(n+1);
            g[n+1].push_back(v);
            mp[v][n+1]=1; right[v]=1;
        }
    }

    int s=0,t=n+1;
    while(1){
        track=false; 
        for(int i=0;i<=n+1;i++) parent[i]=0,vis[i]=0;

        vis[s]=1;
        solve(s,s,t,INF);
        if(track==false) break;
    }

    cout<<total_flow<<"\n";
}
