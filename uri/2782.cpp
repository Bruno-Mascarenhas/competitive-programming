#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x, ans=1, cur, tmp;
    cin>>n;
    if(n <= 2 ) return cout<<1<<endl,0;
    vector<int> arr(2);
    cin>>arr[0]>>arr[1];
    cur = arr[1] - arr[0];

    for(int i=2; i<n; i++){
        cin>>x;
        arr.push_back(x);
        tmp = x-arr[i-1];
        if(tmp != cur)
            cur = tmp, ans++;
    }
    
    cout<<ans<<endl;
}