#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __int128 il;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

int arr[N];

void merge(int st,int ed){
    int mid=(st+ed)/2;
    int L=mid-st+1,R=ed-mid;
    int A[L+1],B[R+1];

    int j=-1;
    for(int i=st;i<=mid;i++) A[++j]=arr[i];

    j=-1;
    for(int i=mid+1;i<=ed;i++) B[++j]=arr[i];

    int l=0,r=0;
    A[L]=mod; B[R]=mod;
    for(int i=st;i<=ed;i++){
        if(A[l]<=B[r]) arr[i]=A[l],l++;
        else arr[i]=B[r],r++;
    }
}

void solve(int st,int ed){
    if(st==ed) return;

    int mid=(st+ed)/2;
    solve(st,mid);
    solve(mid+1,ed);

    merge(st,ed);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    solve(0,n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";
}



