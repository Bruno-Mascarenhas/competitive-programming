#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

int memo[110][110], n, v, bigg = 100100;

int solve(int city, int gas){
    if(city == n) return memo[city][gas] = 0;
    
    if(memo[city][gas] != bigg) return memo[city][gas];

    for(int i=0; i<=(v-gas); i++){
        if(i || gas)
            memo[city][gas] = min(memo[city][gas], solve(city+1,gas+i-1) + (city)*i );
    }

    return memo[city][gas];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>v;

    for(int i=0; i<n+1; i++) for(int j=0; j<n+1; j++) memo[i][j] = bigg;
    cout<<solve(1,1)+1<<endl;
}