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

const int maxn = 3*1e5+10;
vector<vector<int>> graph, graphr;
vector<int> order, component;
bitset<maxn> vis;
 
void dfs1(int src){
    vis[src] = 1;
 
    for(int to: graph[src])
        if(!vis[to])
            dfs1(to);
    
    order.pb(src);
}
 
void dfs2(int src){
    vis[src] = 1;
    component.pb(src);
 
    for(int to: graphr[src])
        if(!vis[to])
            dfs2(to);
}
 
int main(){
    DESYNC;
    int t;
    cin>>t;
    while(t--){
        int n; string s; cin>>n>>s;
 
        graph.assign(n, vector<int>());
        graphr.assign(n, vector<int>());

        for(int i=0; i<n; i++){
            int j = (i+1)%n;
            if(s[i] == '-'){
                graph[i].pb(j);
                graph[j].pb(i);
                //reverse graph (kosaraju algorithm)
                graphr[i].pb(j);
                graphr[j].pb(i);
            } else if(s[i] == '>') graph[i].pb(j), graphr[j].pb(i);
            else graph[j].pb(i), graphr[i].pb(j);
        }
  
        vis.reset();
        for(int i=0; i<n; i++)
            if(!vis[i])
                dfs1(i);
 
        vis.reset();
        reverse(order.begin(), order.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            int v = order[i];
            if(!vis[v]){
                dfs2(v);
                if(component.size() >= 2) ans += component.size();
                //debug(component.size());
                component.clear();
            }
        }
    
        cout<<ans<<endl;
 
        component.clear(); order.clear();
    }
}