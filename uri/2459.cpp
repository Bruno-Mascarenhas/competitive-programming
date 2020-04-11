#include <bits/stdc++.h>
using namespace std;
 
struct t_aresta{
    int dis;
    int x, y;
    int c;
};
 
bool comp(t_aresta a, t_aresta b){ 
  if (a.c == b.c)
    return a.dis < b.dis;
  return a.c > b.c;
}
 
#define MAXN 1010
#define MAXM 2020202
 
int n, m; 
t_aresta edges[MAXM];
 
int pai[MAXN];
int peso[MAXN];
 
t_aresta mst[MAXM];
 
int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}
 
void join(int a, int b){
    a = find(a);
    b = find(b);
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }   
}
 
int main(){
    int teste =0, r;
    cin >> n >> m >> r;
      
      for(int i = 1;i <= m+r;i++){
          cin >> edges[i].x >> edges[i].y >> edges[i].dis;
          (i <= m) ? edges[i].c = 2 : edges[i].c = 1;
      }
      
      for(int i = 1;i <= n;i++) pai[i] = i;
      
      sort(edges+1, edges+m+r+1, comp);
      
      int size = 0;
      for(int i = 1;i <= m+r;i++){
          
          if( find(edges[i].x) != find(edges[i].y) ){ 
              join(edges[i].x, edges[i].y);            
              mst[++size] = edges[i];
          }
      }
      long long ans = 0;
      for(int i = 1;i < n;i++) ans+= mst[i].dis;
 
      cout<<ans<<endl;
    return 0;
} 