#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __int128 il;

const ll N=2e5+5;
const ll mx=1e18+7;
const double pi=acos(-1);

ll dist[N],parent[N];
vector<pair<ll,ll>>g[N];

void solve(){
    priority_queue<pair<ll,ll>,
    vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    pq.push({0,1});
    while(!pq.empty()){
        auto [x,u]=pq.top(); pq.pop();
        if(dist[u]<x) continue;

        for(auto &[v,w]:g[u]){
            if(dist[v]>dist[u]+w){
                parent[v]=u;
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m; cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dist[1]=0;
    for(ll i=2;i<=n;i++) dist[i]=mx;
    solve();

    if(dist[n]==mx){
        cout<<-1<<"\n"; return 0;
    }

    ll v=n;
    vector<ll>ans;
    while(v){
        ans.push_back(v); v=parent[v];
    } 

    // shortest path

    //cout<<dist[n]<<"\n";
    reverse(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
