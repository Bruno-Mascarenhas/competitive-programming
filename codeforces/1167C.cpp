#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn = 1e6;
int pai[maxn],peso[maxn],qtd[maxn];

int find(int x){
    return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x, int y){
    x=find(x);    y=find(y);
    if(x==y)   return;
    if(peso[x]<peso[y]){    
         pai[x]=y;
         qtd[y]+=qtd[x]; 
    } 
    if(peso[x]>peso[y]){
         pai[y]=x;
         qtd[x]+=qtd[y];
    }
    if(peso[x]==peso[y]){
        pai[x]=y;
        peso[y]++;
        qtd[y]+=qtd[x];
    }
}

int n,m, tmp, x, arr[maxn];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){ pai[i] = i; qtd[i] = 1;}
    while(m--){
        cin>>tmp;
        for(int i=0; i<tmp; i++){
            cin>>arr[i];
            if(i) join(arr[i-1],arr[i]);
        }
    }
    for(int i=1; i<=n; i++)
        cout<<qtd[find(i)]<<" ";
    cout<<endl;
}