#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//Compilation flags // g++ -std=c++17 -O3 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g 
using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define pi 3.1415926535897932384626
#define pb push_back
#define EPS 1e-9
#define INF 1e18
#define m1(x) memset((x), -1, sizeof(x))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9+7;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;
vector<bool> vis;
vector<int> ans, p;

int dfs(int node, int cnt){
	if(vis[node]) return cnt-1;
	
	vis[node] = 1;
	cnt = dfs(p[node], cnt+1);

	return ans[node] = cnt;
}

int32_t main() {
	DESYNC;
	cin.exceptions(cin.failbit);
	int t, n; cin>>t;
	while(t--){
		cin>>n;
		vis.assign(n+1, false);
		ans.assign(n+1, 0);
		p.assign(n+1, 0);

		for(int i=1; i<=n; i++) cin>>p[i];

		for(int i=1; i<=n; i++)
			if(!vis[i]) dfs(i, 1);

		for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
}