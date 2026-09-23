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

    string A,B; cin>>A>>B;
    int n=A.size(),m=B.size();

    int dp[n+1][m+1];
    for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    // Find LCS
    
    int l=n,r=m;
    string ans="";
    while(l>=0 && r>=0){
        if(l<=0 && r<=0) break;

        if(l>0 && dp[l-1][r]==dp[l][r]) l--;
        else if(r>0 && dp[l][r-1]==dp[l][r]) r--;
        else if(dp[l][r]==dp[l-1][r-1]+1){
            ans+=A[l-1]; l--; r--;
        }
    }

    cout<<dp[n][m]<<"\n";
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
}
