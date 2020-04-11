#include <bits/stdc++.h>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
using namespace std;
const int maxn = 1e7+10;
bool nprime[maxn];

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i=2; i<maxn; i++){
        if(nprime[i]) continue;
        for(int j=i*2; j<maxn; j+=i)
            nprime[j] = 1;
    }
}

bool arrojado(string x){
    int n;
    for(int i=1; i<=x.size(); i++){
        n = stoi(x.substr(0,i));
        //cout<<n<<endl;
        if(nprime[n]) return false;
    }
    return true;
}

int32_t main(){
    DESYNC;
    int n; string x;
    cin>>n;
    sieve();
    while(n--){
        cin>>x;
        arrojado(x) ? cout<<"S\n" : cout<<"N\n";
    }
}