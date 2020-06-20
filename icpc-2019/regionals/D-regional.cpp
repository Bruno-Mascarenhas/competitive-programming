#include <bits/stdc++.h>
#define int long long
#define debug(x) //cout << #x << " = " << x << endl
#define MAX int32_t(1e6+1)
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
using namespace std;

vi p(MAX, 0), adj[MAX];
vii leafs;

void dfs(int s, int nvl){
	if(adj[s].size() == 0)
		leafs.pb({nvl, s});
	for(auto i : adj[s])
		dfs(i, nvl+1);
}

bool cmp(ii i, ii j){
	return i.first > j.first or (i.first == j.first and i.second < j.second);
}

int32_t main(){
	int n, k;
	cin >> n >> k;

	for(int i=2; i<=n; ++i){
		cin >> p[i];
		adj[p[i]].pb(i);
	}

	dfs(1, 0);
	sort(leafs.begin(), leafs.end(), cmp);

	vi outs, vis(MAX, 0);
	for(auto pp:leafs){
		int i = pp.second, res = 1;
		vis[i] = true;
		while(p[i] and !vis[p[i]]){
			res++;
			i = p[i];
			vis[i] = true;
		}
		outs.pb(res);
	}

	int ans = 0;
	sort(outs.rbegin(), outs.rend());
	for(int i = 0; i < min(k, (int)outs.size()); ++i)
		ans += outs[i];
	cout << ans << endl;
	return 0;
}
