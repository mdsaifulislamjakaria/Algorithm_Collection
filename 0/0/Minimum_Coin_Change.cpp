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

    int n,sum; cin>>n>>sum;
    vector<int>coin(n);
    for(int i=0;i<n;i++) cin>>coin[i];

    int dp[sum+1]; dp[0]=0;
    for(int i=1;i<=sum;i++){
        dp[i]=mod;
        for(int c:coin){
            if(c<=i) dp[i]=min(dp[i],dp[i-c]+1);
        }
    }

    if(dp[sum]==mod) cout<<-1<<"\n";
    else cout<<dp[sum]<<"\n";
}
