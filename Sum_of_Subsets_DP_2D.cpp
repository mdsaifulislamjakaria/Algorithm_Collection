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

    int dp[n+1][T+1];
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=0;i<=T;i++) dp[0][i]=0;
    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        int item=v[i-1];
        for(int j=1;j<=T;j++){
            if(item<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-item]);
            }
            else dp[i][j]=dp[i-1][j];
        } 
    } 

    if(dp[n][T]) cout<<"Possible\n";
    else cout<<"Impossible\n";
}
