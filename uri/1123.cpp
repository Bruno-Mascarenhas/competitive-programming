#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
const int INF = 1e6;
typedef vector<pair<int,int>> pii;

vector<pii> graph;
vector<int> dist, vis;
int n,c,m,k;

void dijkstra(int src){
    vis.assign(n,0);
    dist[src] = 0;

    priority_queue<pair<int,int>,pii,greater<pair<int,int>> > fila;

    fila.push({0,src});

    while(1){
        int cur = -1;

        while(!fila.empty()){
            int nx = fila.top().second;
            fila.pop();

            if(!vis[nx]){
                cur = nx;
                break;
            }
        }

        if(cur == -1) break;
        vis[cur] = 1;

        for(auto it: graph[cur]){
            int price = it.first;
            int nx = it.second;

            if(dist[nx] > dist[cur]+price){
                dist[nx] = dist[cur]+price;
                fila.push({dist[nx],nx});
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m>>c>>k && n+m+c+k){
        graph.assign(n,pii());
        dist.assign(n,INF);
        for(int i=0; i<m; i++){
            int u, v, p;
            cin>>u>>v>>p;

            if(u<c && v<c && abs(u-v) == 1){
                graph[u].push_back({p,v});
                graph[v].push_back({p,u});
            }
            else if(v<c && u>=c)
                graph[u].push_back({p,v});
            else if(u<c && v>=c)
                graph[v].push_back({p,u});
            else if(u>=c && v>=c){
                graph[u].push_back({p,v});
                graph[v].push_back({p,u});        
            }
        }
        dijkstra(k);
        cout<<dist[c-1]<<endl;
    }
}