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
    vector<pair<int,int>>edges;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        edges.push_back({u,v});
    }

    map<int,int>vis;
    vector<int>ans;
    for(int i=0;i<m;i++){
        auto [u,v]=edges[i];
        if(vis[u]==0 && vis[v]==0){
            ans.push_back(u);
            ans.push_back(v);
            vis[u]=1; vis[v]=1;
        }
    }

    cout<<ans.size()<<"\n";
    for(int v:ans) cout<<v<<" ";
}
