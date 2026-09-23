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

    int n,T; cin>>n>>T;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int dp[T+1]; dp[0]=1;
    for(int i=1;i<=T;i++) dp[i]=0;

    for(int i=0;i<n;i++){
        int item=v[i];
        for(int j=T;j>=item;j--){
            dp[j]=max(dp[j],dp[j-item]);
        }
    }

    for(int i=0;i<=T;i++) cout<<dp[i]<<" ";
    cout<<"\n";
}
