#include <bits/stdc++.h>
#define pb push_back
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
using namespace std;
typedef vector<int> vi;


int32_t main(){
    DESYNC;
    int n;
    cin>>n;
    vi seq[31];
    seq[0].pb(1);
    for(int i=1; i<n; i++){
        int curr = seq[i-1][0], j=0, cont=0;
        while(j < seq[i-1].size()){
            if(seq[i-1][j] == curr) j++,cont++;
            else{
                seq[i].pb(cont);seq[i].pb(curr);
                curr = seq[i-1][j]; cont = 1; j++;
            }
        }    
        seq[i].pb(cont);seq[i].pb(curr);    
    }
    for(int c:seq[n-1]) cout<<c;
    cout<<endl;
}