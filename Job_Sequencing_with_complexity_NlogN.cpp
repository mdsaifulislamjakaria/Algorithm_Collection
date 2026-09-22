#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __int128 il;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

int mp[4*N],ans[N],track=0;

void build(int st,int ed,int idx){
    if(st==ed){
        mp[idx]=1; return;
    }

    int mid=(st+ed)/2;
    build(st,mid,2*idx);
    build(mid+1,ed,2*idx+1);

    mp[idx]=mp[2*idx]+mp[2*idx+1];
}

void update(int st,int ed,int l,int r,int val,int idx){
    if(mp[idx]==0 || track>0) return;
    if(st>r || ed<l) return;
    if(st==ed){
        track=1; ans[st]=val; mp[idx]=0; return;
    }

    int mid=(st+ed)/2;
    update(mid+1,ed,l,r,val,2*idx+1);
    update(st,mid,l,r,val,2*idx);

    mp[idx]=mp[2*idx+1]+mp[2*idx];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<pair<int,int>>vc;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        vc.push_back({b,a});
    }

    sort(vc.begin(),vc.end(),greater<pair<int,int>>());

    build(0,n-1,1);

    for(auto [x,y]:vc){ 
        --y; track=0;
        update(0,n-1,0,y,x,1);
    }

    int sum=0;
    for(int i=0;i<n;i++) sum+=ans[i];
    cout<<sum<<"\n";
}
