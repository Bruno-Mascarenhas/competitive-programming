#include <bits/stdc++.h>
#define int long long
#define ss second
#define ff first
using namespace std;
const int M = 1000000007;

int mod(int x, int m = M){
    x %= m;
    return x < 0 ? x+m : x;
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, x, ans = 0;
    cin>>n>>m>>k;

    vector<int> a(n+1,0), b(m+1,0);

    for(int i=1; i<=n; i++){
        cin>>x;
        a[i] = a[i-1] + x;
    }

    for(int i=1; i<=m; i++){
        cin>>x;
        b[i] = b[i-1] + x;
    }

    int j = m;
    for(int i=0; i<=n; i++){
        if(a[i] > k) break;
        
        while(m >= 0 && b[j] > k-a[i]) j--;

        ans = max(ans,i+j);
    }
    
    cout<<ans<<endl;

}