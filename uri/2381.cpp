#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin>>n>>k;
    vector<string> arr(n);
    for(auto &x: arr) cin>>x;
    sort(arr.begin(), arr.end());
    cout<<arr[k-1]<<endl;    
}