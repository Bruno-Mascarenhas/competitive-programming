#include <bits/stdc++.h>
#define pb push_back
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;

vector<int> fib;

char fib_c(int n, int i){
    if(i == 1) return 'B';
    if(i == 2) return 'A';

    if(n <= fib[i-1])
        return fib_c(n,i-1);
    else
        return fib_c(n-fib[n-1],i-2);
}

char fib_w(int n, int i){
    if(i == 1) return 'B';
    if(i == 2) return 'A';

    if(n <= fib[i-2])
        return fib_w(n,i-2);
    else
        return fib_w(n-fib[n-2],i-1);
}

int32_t main(){
    int n,x; cin>>n;
    fib.push_back(0);fib.push_back(1);
    for(int i=2;i<90; i++)
        fib.push_back(fib[i-1]+fib[i-2]);
    while(n--){
        cin>>x;
        auto k = lower_bound(fib.begin(),fib.end(),x)-fib.begin();

        if(fib_c(x,k) != fib_w(x,k)){
            cout<<"WA\n";
            return 0;
        }
    }
    cout<<"AC\n";
}