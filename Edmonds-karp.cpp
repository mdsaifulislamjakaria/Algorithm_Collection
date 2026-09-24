#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
//typedef __int128 il;
 
const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,m; cin>>n>>m;
    vector<int>g[n+1];
    for(int i=1;i<=n;i++) g[i].clear();
 
    ll mp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            mp[i][j]=0;
        }
    }

    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back(v); mp[u][v]+=w;
        g[v].push_back(u);
    }
 
    ll ans=0;
    bool track=true;
    while(track){
        track=false;
        queue<int>q; q.push(1);
        bool vis[n+1]; ll arr[n+1],parent[n+1];
        for(int i=1;i<=n;i++) vis[i]=false,arr[i]=0;
 
        vis[1]=true; arr[1]=mod;
        while(!q.empty() && !vis[n]){
            int u=q.front(); q.pop();
            for(int v:g[u]){
                if(mp[u][v]>0 && !vis[v]){
                    vis[v]=true; parent[v]=u; 
                    q.push(v); arr[v]=min(mp[u][v],arr[u]);
                }
            }
        }
 
        if(vis[n]){
            track=true; int x=n; ans+=arr[n];
            while(x!=1){
                mp[parent[x]][x]-=arr[n]; mp[x][parent[x]]+=arr[n];
                x=parent[x]; 
            } 
        }
    }
 
    cout<<ans<<"\n";
}
