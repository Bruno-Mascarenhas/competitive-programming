#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int p, r, x, t=0;

    while(cin>>p>>r && p+r){
        list<int> arr;

        for(int i=0; i<p; i++){
            cin>>x;
            arr.push_back(x);
        }

        int qtd, ord;
        
        while(arr.size()>1){
            cin>>qtd>>ord;
            auto it = arr.begin();
            for(int i=0; i<qtd; i++){
                cin>>x;
                (x!=ord) ? it = arr.erase(it) : ++it;
            }
        }

        cout<<"Teste "<<++t<<endl;
        cout<<*arr.begin()<<endl;
        cout<<endl;
    }
}