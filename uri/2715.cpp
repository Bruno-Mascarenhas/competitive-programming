#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int MAXN = 1e6+10;
ll psum[MAXN], ssum[MAXN], arr[MAXN], n;


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i) psum[i] = psum[i-1]+arr[i];
            else psum[i] = arr[i];
        }
        
        for(int i=n-1; i>=0; i--)
            if(i<n-1) ssum[i] = ssum[i+1]+arr[i];
            else ssum[i] = arr[i];
        
        ll ans = arr[0];

        for(int i=0; i<n-1; i++)
            ans = min(ans,llabs(psum[i]-ssum[i+1]));

        cout<<ans<<endl;
    }

}
