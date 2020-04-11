#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, p, r;
    while(cin>>n){
        int bigg=0, qtd=0;
        for(int i=0; i<n-1; i++){
            cin>>p>>r;
            if(p > bigg){
                bigg = p;
                r ? qtd=0: qtd=1;
            }
            else if(r) 
                qtd++;   
        }

        cout<<qtd<<endl;
    }

}