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

    int n; cin>>n;
    vector<pair<int,int>>vc;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        vc.push_back({b,a});
    }

    sort(vc.begin(),vc.end(),greater<pair<int,int>>());

    int ans[n+1];
    for(int i=0;i<=n;i++) ans[i]=0;

    for(auto &[x,y]:vc){
        for(int i=y;i>=1;i--){
            if(ans[i]==0){
                ans[i]=x; break;
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
