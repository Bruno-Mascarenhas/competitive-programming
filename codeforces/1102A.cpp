#include <iostream>
#include <vector>
#include <numeric>
#define endl "\n"
#define int long long
#define debug(x) cout << #x " = " << (x) << endl
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;

    cout<<(((long long)n*(n+1))/(long long)2)%2<<endl;
}