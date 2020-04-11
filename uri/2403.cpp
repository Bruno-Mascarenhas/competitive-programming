#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    
    vector<int> ans, grau(n);
    vector<vector<int>> graph(n, vector<int>());
    set<int> lista;

    for(int i=0; i<m; i++){
        cin>>a>>b;
        grau[b]++;
        graph[a].push_back(b);
    }
    for(int i=0; i<n; i++) if(grau[i] == 0) lista.insert(i);

    while(!lista.empty()){
        int cur = *lista.begin();
        lista.erase(lista.begin());
        
        for(int nx: graph[cur]){
            grau[nx]--;
            if(grau[nx] == 0) lista.insert(nx);
        }

        ans.push_back(cur);
    }

    if(ans.size() < n) cout<<"*\n";
    else   
        for(int x: ans) cout<<x<<endl;
}