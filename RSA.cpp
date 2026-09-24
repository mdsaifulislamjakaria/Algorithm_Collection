#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Modular Exponentiation: (b^p) % m
ll modpow(ll b, ll p, ll m) {
    ll res = 1;
    b %= m;
    while (p > 0) {
        if (p & 1) res = (res * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Inputs: Two prime numbers p and q
    ll p, q; cin >> p >> q;

    ll n = p * q;
    ll phi = (p - 1) * (q - 1);

    // 2. Choose e such that gcd(e, phi) == 1
    ll e = 3;
    while (__gcd(e, phi) != 1) e++;

    // 3. Simple Loop to find d: (d * e) % phi == 1
    ll d = 1;
    while ((d * e) % phi != 1) d++;

    cout << "Public Key (e, n): (" << e << ", " << n << ")\n";
    cout << "Private Key (d, n): (" << d << ", " << n << ")\n";

    // Message input (M < n)
    ll msg; cin >> msg;

    // Encryption: C = (M^e) % n
    ll cipher = modpow(msg, e, n);
    cout << "Encrypted: " << cipher << "\n";

    // Decryption: M = (C^d) % n
    ll decrypted = modpow(cipher, d, n);
    cout << "Decrypted: " << decrypted << "\n";
}