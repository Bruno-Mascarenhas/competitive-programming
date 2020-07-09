#include <bits/stdc++.h>
#define int long long
#define ss second
#define ff first
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;

    vector<pair<int,int>> primes;
    set<int> nums;

    for(int i=2; i*i <= n; i++){
        if(n%i == 0){
            int qtd = 0;
            while(n%i == 0) n/=i, qtd++;
            primes.push_back({i,qtd});
        }
    }
    
    if(n > 1) primes.push_back({n,1});

    for(pair<int,int> &x: primes){
        int prime = x.first, factor = x.second, cnt = 1;
        while(factor >= cnt){
            nums.insert(prime);
            factor -= cnt;
            cnt++;
            prime = pow(x.first,cnt);
        }
    }

    cout<<nums.size()<<endl;
    // for(int x: nums) cout<<x<<" ";
    // cout<<endl;
}