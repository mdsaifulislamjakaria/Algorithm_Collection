#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __ll128 il;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

ll vis[N],ans=0,cnt=0;
vector<pair<ll,ll>>g[N];

void solve(ll n){
    vis[1]=1; cnt++;
    priority_queue<pair<ll,ll>,
    vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    for(auto &[v,w]:g[1]){
        pq.push({w,v});
    }

    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(vis[u]==1) continue;
        vis[u]=1; ans+=w; cnt++;
        for(auto &[v,weight]:g[u]){
            if(!vis[v]){
                pq.push({weight,v});
            }
        }
    }

    if(cnt==n) cout<<ans<<"\n";
    else cout<<"IMPOSSIBLE\n";
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

    solve(n);
}
