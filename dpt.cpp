#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e5+10;
vector<int> vizinhos[M];
int n, comp[M], PD[M][2], pai[M];

int VertexCover(int X, int pai_colorido){
	
	if(PD[X][pai_colorido] != -1) 
		return PD[X][pai_colorido];
	
	int caso1 = comp[X], caso2 = 0;
	
	for(int i = 0;i < (int)vizinhos[X].size();i++){ 
		
		int V = vizinhos[X][i];
		
		if(V == pai[X]) continue; 
        pai[V] = X; 
		caso1 += VertexCover(V, true); 
		caso2 += VertexCover(V, false); 
	}
	
	if(pai_colorido == true) PD[X][pai_colorido] = max(caso1, caso2);
	if(pai_colorido == false) PD[X][pai_colorido] = caso1;
	
	return PD[X][pai_colorido]; 
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    int u, v;
    memset(PD, -1, sizeof PD);
    for(int i=0; i<n-1; i++){
        cin>>u>>v; u--,v--;
        vizinhos[u].push_back(v);
        vizinhos[v].push_back(u);
    }
    for(int i=0; i<n; i++){
        cin>>comp[i];
    }
    cout<<VertexCover(0,true)<<endl;

}