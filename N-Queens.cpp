#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//typedef __int128 il;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

bool track=false;
char grid[20][20];
map<int,int>row,column,diag1,diag2;

void solve(int current,int n){
    if(track) return;
    if(current==n+1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<grid[i][j]<<" ";
            } cout<<"\n";
        }
        track=true; return;
    }

    for(int i=1;i<=n;i++){
        if(column[i]==0 && diag1[current-i]==0 && diag2[current+i]==0){
            grid[current][i]='Q';
            column[i]=1; diag1[current-i]=1; diag2[current+i]=1;

            solve(current+1,n);

            grid[current][i]='.';
            column[i]=0; diag1[current-i]=0; diag2[current+i]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            grid[i][j]='.';
        }
    }
    solve(1,n);
}
