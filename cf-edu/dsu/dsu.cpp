#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5+100;
 
int sz[maxn], link[maxn];
 
int get(int x){
    return link[x] == x ? x : link[x] = get(link[x]);
}
 
void unite(int a, int b){
    a = get(a), b = get(b);

    if(a == b) return;
 
    if(sz[a] < sz[b]) swap(a, b);
 
    link[b] = a;
    sz[a] += sz[b];
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
 
    for(int i=0; i<=n; i++) link[i] = i, sz[i] = 1;
 
    while(q--){
        string op; int a, b;
        cin>>op>>a>>b;
 
        if(op == "union") unite(a, b);
        else cout<<(get(a) == get(b) ? "YES":"NO")<<endl;
    }
}