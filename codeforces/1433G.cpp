#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
#define int long long
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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

const int maxn = 1010;

vector<pii> graph[maxn];

int32_t main(){
    DESYNC;
    int n, m, k, u, v, w;
    cin>>n>>m>>k;

    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        u--, v--;
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }

    vector<int> dist[n];
    for(int i=0; i<n; i++){
        priority_queue<pii> pq;
        vector<int> n_dist(n, INT_MAX);
        vector<bool> vis(n, 0);
        n_dist[i] = 0;
        pq.push({0, i});

        while(!pq.empty()){
            int node = pq.top().second; pq.pop();

            if(vis[node]) continue;
            vis[node] = 1;

            for(auto x: graph[node]){
                int to = x.first, wg = x.second;

                if(n_dist[to] > n_dist[node] + wg){
                    n_dist[to] = n_dist[node] + wg;
                    pq.push({-n_dist[to], to});
                }
            }
        }
        dist[i] = n_dist;
    }

    vector<pii> paths(k);
    for(pii &x: paths){ cin>>x.first>>x.second; x.first--, x.second--; }

    int ans = INT_MAX;
    for(int i=0; i<n; i++)
        for(auto [node, _]: graph[i]){
            int tmp = 0;
            for(auto [a, b]: paths)
                tmp += min({dist[a][b], dist[a][node] + dist[i][b], dist[a][i] + dist[node][b] });
            ans = min(ans, tmp);
        }

    cout<<ans<<endl;
}