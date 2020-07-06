#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;

        vector<int> arr(n);
        for(int &x: arr) cin>>x;

        sort(arr.begin(), arr.end());

        if(arr.back() - arr[0] > k*2){
            cout<<-1<<endl;
            continue;
        }

        int ans = (arr[0]+arr.back())/2;

        if(abs(arr[0] - ans) < k) ans = abs(k + arr[0]);
        
        cout<<ans<<endl;
    }
}