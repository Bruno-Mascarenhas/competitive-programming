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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

const int maxn = 70;
int dp[maxn][maxn][maxn][maxn], n, m, k, mat[maxn][maxn];

int f(int r, int c, int rem, int qtd){
    if(r == n) return (rem==0 ? 0:INT_MIN);

    if(c == m || qtd+1 > m/2) return f(r+1, 0, rem, 0);

    int &ans = dp[r][c][rem][qtd];

    if(ans != -1) return ans;
    ans = INT_MIN;

    return ans = max({ans, f(r,c+1,(rem+mat[r][c])%k,qtd+1)+mat[r][c], f(r,c+1,rem,qtd)});
}

int32_t main(){
    DESYNC;
    memset(dp, -1, sizeof(dp));

    cin>>n>>m>>k;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    cout<<max(0,f(0,0,0,0))<<endl;
}