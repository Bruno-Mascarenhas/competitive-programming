#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int INF = 1LL<<31;

vector<int> dist;
vector<bool> vis;
vector<vector<pii>> graph; //first = w | second = vertex

int dijkstra(int source, int dest){
    dist[source] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,source});

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();

        int u = top.second;

        if(vis[u]) continue;
        vis[u] = 1;

        for(pii to: graph[u]){
            int v = to.second, w = to.first;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

    return dist[dest];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, x, y, w;
    cin>>n>>m;
    vis.assign(n+2,0);
    dist.assign(n+2,INF);
    graph.assign(n+2, vector<pii>());
    
    for(int i=0; i<m; i++){
        cin>>x>>y>>w;
        graph[x].push_back({w,y});
        graph[y].push_back({w,x});
    }

    cout<<dijkstra(0,n+1)<<endl;
}