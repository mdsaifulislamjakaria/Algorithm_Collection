#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

// Modular Exponentiation: (b^p) % m (using __int128 to handle overflow)
ll modpow(ll b,ll p,ll m){
    ll res=1;
    b%=m;
    while(p>0){
        if(p&1) res=(ll)((__int128)res*b%m);
        b=(ll)((__int128)b*b%m);
        p>>=1;
    }
    return res;
}

// Extended GCD: ax + by = gcd(a, b)
ll extgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1; y=0;
        return a;
    }
    ll x1,y1;
    ll d=extgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

// Modular Multiplicative Inverse: (a * d) % m == 1
ll modInverse(ll a,ll m){
    ll x,y;
    ll g=extgcd(a,m,x,y);
    if(g!=1) return -1;
    return (x%m+m)%m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Inputs: Two prime numbers p and q
    ll p,q; cin>>p>>q;

    // 2. Compute n and phi(n)
    ll n=p*q;
    ll phi=(p-1)*(q-1);

    // 3. Choose e such that gcd(e, phi) == 1
    ll e=3;
    while(e<phi && __gcd(e,phi)!=1) e++;

    // 4. Compute d = e^-1 mod phi
    ll d=modInverse(e,phi);

    cout<<"Public Key (e, n): ("<<e<<", "<<n<<")\n";
    cout<<"Private Key (d, n): ("<<d<<", "<<n<<")\n";

    // Message input (M < n)
    ll msg; cin>>msg;

    // Encryption: C = (M^e) % n
    ll cipher=modpow(msg,e,n);
    cout<<"Encrypted Ciphertext: "<<cipher<<"\n";

    // Decryption: M = (C^d) % n
    ll decrypted=modpow(cipher,d,n);
    cout<<"Decrypted Message: "<<decrypted<<"\n";
}