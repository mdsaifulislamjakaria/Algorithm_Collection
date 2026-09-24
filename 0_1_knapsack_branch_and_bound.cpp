#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

// সাবট্রির সর্বোচ্চ সম্ভাব্য লাভ (Upper Bound) বের করা (Fractional Knapsack লজিক)
double getBound(ll lvl,ll w,ll p,ll n,ll W,vector<tuple<double,ll,ll>>&items){
    if(w>=W) return 0; // ব্যাগ ওভারফ্লো হলে ইনভ্যালিড বাউন্ড
    
    double bound=p;
    ll j=lvl+1;
    ll totw=w;
    
    // ব্যাগে যতটুকু জায়গা আছে, সম্পূর্ণ আইটেম ঢোকানো
    while(j<n){
        auto [r,v,wt]=items[j];
        if(totw+wt>W) break;
        totw+=wt;
        bound+=v;
        j++;
    }
    
    // ব্যাগের বাকি জায়গায় পরবর্তী আইটেমটির ভগ্নাংশ (Fraction) ঢোকানো
    if(j<n){
        auto [r,v,wt]=items[j];
        bound+=(W-totw)*r;
    }
    return bound;
}

// Branch and Bound (Best-First Search) লজিক
ll knapsackBB(ll W,vector<tuple<double,ll,ll>>&items){
    ll n=items.size();
    
    // আইটেমগুলোকে ratio (value/weight) অনুযায়ী বড় থেকে ছোট (Descending) সাজানো
    sort(items.begin(),items.end(),greater<tuple<double,ll,ll>>());

    // Max-Heap: যার Bound সবচেয়ে বেশি, তাকে আগে প্রসেস করবে
    // tuple: <bound, profit, weight, level>
    priority_queue<tuple<double,ll,ll,ll>>pq;
    
    // Root নোড (Level -1) ইনিশিয়ালাইজ করা
    double rootBound=getBound(-1,0,0,n,W,items);
    pq.push({rootBound,0,0,-1});

    ll maxProfit=0;
    while(!pq.empty()){
        auto [b,p,w,lvl]=pq.top();
        pq.pop();

        // Pruning: যদি বর্তমান নোডের সর্বোচ্চ সম্ভাবনা (bound) বর্তমান maxProfit-এর চেয়ে কম হয়, তবে এটি বাদ
        if(b<=maxProfit || lvl>=n-1) continue;

        ll nextLvl=lvl+1;
        auto [r,v,wt]=items[nextLvl]; // ইনডেক্স দিয়ে পরবর্তী আইটেম অ্যাক্সেস

        // অপশন ১: পরবর্তী আইটেমটি ব্যাগে নেওয়া (Take)
        ll nextW=w+wt;
        ll nextP=p+v;

        if(nextW<=W){
            if(nextP>maxProfit) maxProfit=nextP; // গ্লোবাল ম্যাক্সিমাম প্রফিট আপডেট
            double nextB=getBound(nextLvl,nextW,nextP,n,W,items);
            if(nextB>maxProfit) pq.push({nextB,nextP,nextW,nextLvl}); // প্রমিজিং হলে Queue তে পুশ
        }

        // অপশন ২: পরবর্তী আইটেমটি ব্যাগে না নেওয়া (Don't Take)
        double nextB=getBound(nextLvl,w,p,n,W,items);
        if(nextB>maxProfit) pq.push({nextB,p,w,nextLvl}); // প্রমিজিং হলে Queue তে পুশ
    }
    return maxProfit;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,W; cin>>n>>W;
    
    // items: <ratio, value, weight>
    vector<tuple<double,ll,ll>>items;
    for(ll i=0;i<n;i++){
        ll v,w; cin>>v>>w;
        items.push_back({(double)v/w,v,w});
    }

    cout<<knapsackBB(W,items)<<"\n";
}