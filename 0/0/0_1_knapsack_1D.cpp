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

    ll n,W; cin>>n>>W;
    vector<pair<int,int>>vc;
    for(int i=0;i<n;i++){
        int weight,value; cin>>weight>>value;
        vc.push_back({weight,value});
    }

    ll dp[W+1]; 
    for(int i=0;i<=W;i++) dp[i]=0;

    for(int i=1;i<=n;i++){
        auto &[w,v]=vc[i-1];
        for(int j=W;j>=1;j--){
            if(w<=j){
                dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
    }

    cout<<dp[W]<<"\n";
}
