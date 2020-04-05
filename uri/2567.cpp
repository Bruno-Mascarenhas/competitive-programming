#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        int ans=0;
        vector<int> arr(n);
        for(auto &x: arr) cin>>x;
        sort(arr.begin(),arr.end());
        if(n == 1) ans=0;
        else{
            for(int i=0; i<n/2; i++){
                ans+=arr[n-i-1] - arr[i];
            }
        }
        cout<<ans<<endl;
    }
}