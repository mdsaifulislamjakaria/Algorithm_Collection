#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __int128 il;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

ll cross(pair<ll,ll>A,pair<ll,ll>B,pair<ll,ll>C){
    auto [Ax,Ay]=A; auto [Bx,By]=B; auto [Cx,Cy]=C;
    ll BAx=Ax-Bx,BAy=Ay-By;
    ll BCx=Cx-Bx,BCy=Cy-By;
    return BAx*BCy-BAy*BCx;
}

void solve(vector<pair<ll,ll>>&point){
    vector<pair<ll,ll>>hull;
    for(ll i=0;i<point.size();i++){
        auto &[x,y]=point[i];
        while(hull.size()>1 && cross(hull[hull.size()-2],hull[hull.size()-1],{x,y})<0){
            hull.pop_back();
        }
        hull.push_back({x,y});
    }

    int k=hull.size();
    for(ll i=point.size()-2;i>=0;i--){
        auto &[x,y]=point[i];
        while(hull.size()>k && cross(hull[hull.size()-2],hull[hull.size()-1],{x,y})<0){
            hull.pop_back();
        }
        hull.push_back({x,y});
    } hull.pop_back();

    cout<<hull.size()<<"\n";
    for(auto [x,y]:hull) cout<<x<<" "<<y<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        ll n; cin>>n;
        if(n==0) break;
        vector<pair<ll,ll>>point;
        map<pair<int,int>,int>mp;
        for(ll i=0;i<n;i++){
            ll x,y; cin>>x>>y;
            if(mp[{x,y}]==0) point.push_back({x,y});
            mp[{x,y}]++;
        }

        sort(point.begin(),point.end());
        if(point.size()<=2){
            cout<<point.size()<<"\n";
            for(auto [x,y]:point) cout<<x<<" "<<y<<"\n";
        }
        else solve(point);
    }
}

