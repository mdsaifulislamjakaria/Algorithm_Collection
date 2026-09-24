#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=2e5+5;
const ll mod=1e9+7;
const double pi=acos(-1);

int partitionTwoPointer(vector<ll>&arr,int low,int high){
    ll pivot=arr[low];
    int l=low+1,r=high;
    while(l<=r){
        while(l<=r && arr[l]<=pivot) l++;
        while(l<=r && arr[r]>pivot) r--;
        if(l<r){
            swap(arr[l],arr[r]);
            l++; r--;
        }
    }
    swap(arr[low],arr[r]);
    return r;
}

void quickSort(vector<ll>&arr,int low,int high){
    if(low<high){
        int pIdx=partitionTwoPointer(arr,low,high);
        quickSort(arr,low,pIdx-1);
        quickSort(arr,pIdx+1,high);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";
}