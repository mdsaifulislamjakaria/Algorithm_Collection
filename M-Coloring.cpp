#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __int128 il;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

bool track;
vector<int>g[N];
int color[N];

void solve(int current_node,int n,int m){
    if(track) return;
    if(current_node==n+1){
        for(int i=1;i<=n;i++) cout<<color[i]<<" ";
        cout<<"\n";
        track=true; return;
    }

    for(int i=1;i<=m;i++){
        bool same=false;
        for(int v:g[current_node]){
            if(color[v]==i){
                same=true; break;
            }
        }

        if(same==false){
            color[current_node]=i;
            solve(current_node+1,n,m);
            color[current_node]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,e,m; cin>>n>>e>>m; // n=number of vertex,e=number of edges m=total colors
    for(int i=0;i<e;i++){
        int u,v; cin>>u>>v;
        if(u!=v){
          g[u].push_back(v);
          g[v].push_back(u);
        }
    }

    solve(1,n,m);
    if(track==false){
        cout<<"IMPOSSIBLE\n";
    }
}
