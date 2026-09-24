#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

ll minimax(int depth,int nodeIdx,bool isMax,vector<ll>&scores,int h){
    if(depth==h) return scores[nodeIdx];

    if(isMax){
        return max(minimax(depth+1,nodeIdx*2,false,scores,h),minimax(depth+1,nodeIdx*2+1,false,scores,h));
    }else{
        return min(minimax(depth+1,nodeIdx*2,true,scores,h),minimax(depth+1,nodeIdx*2+1,true,scores,h));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h; cin>>h;
    int n=1<<h;
    vector<ll>scores(n);
    for(int i=0;i<n;i++) cin>>scores[i];

    cout<<minimax(0,0,true,scores,h)<<"\n";
}