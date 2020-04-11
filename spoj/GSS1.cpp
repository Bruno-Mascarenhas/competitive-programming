#include <bits/stdc++.h>
using namespace std;
#define inf -20000
const int maxn = 1e6*2;

int segt[maxn],n,q,x,y;

void build(){
    for(int i=n-1; i>0; --i)
        segt[i] = max(segt[i<<1],segt[i<<1|1]);
}

void modify(int x, int val){
    for(segt[x+=n]=val; x>1; x>>=1) segt[x>>1] = max(segt[x],segt[x^1]);
}

int query(int l, int r){
    int ans = inf;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1) ans = max(ans,segt[l++]);
        if(r&1) ans = max(ans,segt[--r]);
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>segt[n+i];
    build();
    cin>>q;
    //cout<<endl;

    //for(int i=0; i<n*2; i++) cout<<segt[i]<<" "; cout<<endl;

    for(int i=0; i<q; i++){
        cin>>x>>y;x--,y;
        cout<<query(x,y)<<endl;
    }
}