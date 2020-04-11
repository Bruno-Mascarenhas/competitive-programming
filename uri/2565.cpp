#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        vector<double> arr(n);
        for(auto &x:arr) cin>>x;
        sort(arr.begin(),arr.end());
        double med;
        n&1 ? (med = arr[n/2]) : med = (arr[n/2] + arr[n/2-1])/2.0;
        double ans=0;
        for(auto x: arr) ans+=abs(med-x);
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
}