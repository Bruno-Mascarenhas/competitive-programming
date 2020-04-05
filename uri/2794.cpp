#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(auto &it: arr) cin>>it.first>>it.second;
    sort(arr.begin(),arr.end());
    for(int i=1; i<n; i++)
        if(arr[i].second > arr[i-1].second)
            return cout<<"N\n", 0;
    cout<<"S\n";
}