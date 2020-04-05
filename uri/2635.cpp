#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin>>n;
    vector<string> arr(n);
    for(string &x:arr) cin>>x;
    cin>>q;
    string aux;
    while(q--){
        int comp=0, qtd=0;
        cin>>aux;
        for(string x: arr) if(x.find(aux) == 0) comp = max(comp,(int)x.size()),qtd++;
        if(!qtd) cout<<-1<<endl;
        else cout<<qtd<<" "<<comp<<endl;
    }
}