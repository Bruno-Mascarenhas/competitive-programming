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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
const int MOD = 1e9+7;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

ll mod(ll x){
	x %= MOD;
	return x < 0 ? x += MOD : x;
}


int32_t main() {
	DESYNC;
	cin.exceptions(cin.failbit);

	int n, m;
	vector<int> adj[101];
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}

	vector<int> side(n, -1);
	bool is_bipartite = true;
	queue<int> q;
	for (int st = 0; st < n; ++st) {
		if (side[st] == -1) {
			q.push(st);
			side[st] = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int u : adj[v]) {
					if (side[u] == -1) {
						side[u] = side[v] ^ 1;
						q.push(u);
					} else {
						is_bipartite &= side[u] != side[v];
					}
				}
			}
		}
	}

	int l = 0, r = 0;
	for(int x: side){
		if(x == 1) r++;
		else l++;
	}

	//debug(l); debug(r);
	//for(int i=0; i<n; i++) cout<<adj[i].size()<<" ";
	//cout<<endl;
	bool ok = ((l%2==0 && r%2==0) || (l==1 || r==1));

	cout << (is_bipartite && ok ? "Y" : "N") << endl;

}