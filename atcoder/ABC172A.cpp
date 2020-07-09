#include <bits/stdc++.h>
#define int long long
#define ss second
#define ff first
using namespace std;
const int M = 1000000007;

int mod(int x, int m = M){
    x %= m;
    return x < 0 ? x+m : x;
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;

    cout<<n + pow(n,2) + pow(n,3)<<endl;


}