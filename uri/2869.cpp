#include <queue>
#include <iostream>
#include <bitset>
#define int long long
using namespace std;
int n; const int N = 1000000008;

priority_queue<int> backup;
bitset<N> primes;

void sieve(){
    primes.reset();
    for(int i=2; i*i<N; i++){
        if(!primes[i])
        backup.push(i);
        for(int j=i*i; j<N; j+=i)
            primes[i] = 1;
    }
}


void testcase(){
    cin>>n;

    priority_queue<int> divs = backup;

    cout<<backup.size()<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int t; cin>>t;
    while(t--) testcase();
}