#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = INT_MAX-100;

int32_t main(){
    int t, n, m, src; cin>>t;
    while(t--){
        cin>>n>>m;
        vector<pair<int, int>> graph[n];

        for(int i=0; i<m; i++){
            int u, v, w;
            cin>>u>>v>>w;
            u--, v--;
            graph[u].push_back({w,v});
            graph[v].push_back({w,u});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;

        cin>>src; src--;
        vector<int> dist(n, inf), vis(n, 0);
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            int node = pq.top().second; pq.pop();

            if(vis[node]) continue;
            vis[node] = 1;

            for(auto x: graph[node]){
                int w = x.first, to = x.second; 

                if(dist[node] + w < dist[to]){
                    dist[to] = dist[node] + w;
                    pq.push({-dist[to], to});
                }
            }
        }

        for(int i=0; i<n; i++)
            if(i!=src)
                cout<<(dist[i] == inf ? -1 : dist[i])<<" ";
        cout<<endl;
    }
}