#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k, t[(int)(1e5+1)*2], l, r;
char op;

int func(int val){
    if(val > 0) return 1;
    if(val == 0) return 0;
    return -1;
}

void build(){
    for(int i = n-1; i>0;--i) t[i] = t[i<<1] * t[i<<1|1];
}

void update(int pos, int val){
    for(t[pos+=n]=val;pos>>=1;) t[pos] = t[pos<<1] * t[pos<<1|1];
}

char query(int l, int r){
    int res = 1;
    for(l+=n, r+=n; l<r; r>>=1,l>>=1){
        if(l&1) res *= t[l++];
        if(r&1) res *= t[--r];
    }
    //return res;
    if(res>0) return '+';
    else if(res==0) return '0';
    else return '-';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>k){
        for(int i=0; i<n; i++){ cin>>r; t[i+n] = func(r);}

        build();
        while(k--){
            cin>>op>>l>>r;
            if(op == 'C')
                update(--l,func(r));
            else 
                cout<<query(--l,r);
        }
        cout<<endl;   
    }
    return 0;
}