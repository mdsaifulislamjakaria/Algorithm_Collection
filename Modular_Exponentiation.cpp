#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

ll modpow(ll a,ll b){
    ll ans=1;
    a=(a%mod+mod)%mod;
    while(b>0){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod; b=b/2;
    }
    return ans;
}

ll modInverse(ll a){
    return modpow(a,mod-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b; cin>>a>>b;
    ll base=(a%mod+mod)%mod;

    if(b<0){
        if(base==0){
            cout<<"-1\n";
            return 0;
        }
        ll inv_a=modInverse(base); // (1/a preprocess kora hoise) a^-b=(a^-1)^b;
        cout<<modpow(inv_a,abs(b))<<"\n";
    }
    else{
        cout<<modpow(base,b)<<"\n";
    }
}