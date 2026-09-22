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

    int n,c; cin>>n>>c;
    vector<int>val(n),wt(n);
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        val[i]=a; wt[i]=b;
    }

    vector<tuple<double,int,int>>vc;
    for(int i=0;i<n;i++){
        double x=(double) val[i]/(double) wt[i];
        vc.push_back({x,val[i],wt[i]});
    }

    sort(vc.begin(),vc.end(),greater<tuple<double,int,int>>());

    double ans=0;
    for(auto &[x,y,z]:vc){
        if(z<=c){
            ans+=y; c-=z;
        }
        else{
            double p=c*x;
            ans+=p; break;
        }
    }

    cout<<ans<<"\n";
}
