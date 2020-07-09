#include <bits/stdc++.h>
#define int long long
#define ss second
#define ff first
using namespace std;
const int M = 998244353, N = 3001;
int memo[N][N], arr[N], n, s;

int mod(int x, int m = M){
    x %= m;
    return x < 0 ? x+m : x;
}

int solve(int idx, int sum){
    if(sum > s) return 0;

    if(idx == n)
        return sum == s ? 1 : 0;

    if(memo[idx][sum] != -1)
        return memo[idx][sum];

    memo[idx][sum] = mod(mod(2LL*solve(idx+1,sum)) + mod(solve(idx+1,sum+arr[idx])));

    return memo[idx][sum];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(memo, -1, sizeof(memo));
    
    cin>>n>>s;
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<solve(0,0)<<endl;


}