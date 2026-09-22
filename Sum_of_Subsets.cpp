#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __int128 il;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

int arr[N],arr1[N];
deque<int>dq;
bool track=false;

void solve(int index,int size,int sum,int n,int target){
    if(sum==target){
        for(int i=0;i<size;i++) cout<<arr1[i]<<" ";
        cout<<"\n";
        track=true; return;
    }
    if(sum>target|| index==n) return;

    arr1[size]=arr[index];
    solve(index+1,size+1,sum+arr[index],n,target);
    solve(index+1,size,sum,n,target);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,target; cin>>n>>target;
    for(int i=0;i<n;i++) cin>>arr[i];

    solve(0,0,0,n,target);
    if(track==false){
        cout<<"IMPOSSIBLE\n";
    }
}
