#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k, x;
    while(cin>>n>>k){
        vector<int> arr(n);
        for(int &m: arr) cin>>m;
        sort(arr.rbegin(), arr.rend());
        while(k--){
            cin>>x;
            cout<<arr[x-1]<<endl;
        }
    }
}