#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t, n, m, x;
    cin>>t>>n>>m;
    set<int> nums;
    for(int i=0; i<n; i++){
        cin>>x;
        nums.insert(x);
    }
    for(int i=0; i<m; i++){
        cin>>x;
        if(nums.count(x)) nums.erase(x);
    }

    cout<<nums.size()<<endl;

}