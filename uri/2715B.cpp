#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int MAXN = 1e6+10;
ll arr[MAXN], n, ans;


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll tot = accumulate(arr,arr+n,0);
        ll a =0;
        for(int i=0; i<n-1; i++){
            if(a < tot - a)
                a+=arr[i];
            else break;
        }
        ans = tot-a;
        cout<<ans<<endl;
    }

}
