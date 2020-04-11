#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector<bool> arr(n,0);
    for(int j=0; j<m; j++){
        int x, k;
        cin>>x>>k;
        x--;
        arr[x]=1;
        for(int i=x; i<n; i+=k) arr[i] = 1;
        for(int i=x; i>=0; i-=k) arr[i] = 1;
    }

    for(int x: arr) cout<<x<<endl;
}