#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define mt make_tuple
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define EPS 1e-9
#define INF 1e18
#define int long long

const int dx[] = {0,1,0,-1,-1,1,-1,1};
const int dy[] = {1,0,-1,0,-1,1,1,-1};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

int n, dp[201][4540], arr[201];

int solve(int time, int idx){
    if(time == 2*n+10) return INF;
    if(idx == n) return 0;
    int &x = dp[idx][time];
    if(x != -1) return x;
    x = INF;
    return x = min({x,solve(time+1,idx),solve(time+1,idx+1)+abs(arr[idx]-time)});
}

int32_t main(){
    DESYNC;
    int t; cin>>t; 
    while(t--){
        memset(dp, -1, sizeof(dp));
        
        cin>>n;
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr, arr+n);
        
        cout<<solve(1,0)<<endl;
    }
}