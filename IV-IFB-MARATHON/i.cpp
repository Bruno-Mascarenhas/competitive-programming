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

    int a = fib[i-1];
    return a <= n ?  fib_c(n,i-1) : fib_c(n-a,i-2);
}

char fib_w(int n, int i){
    if(i == 1) return 'B';
    if(i == 2) return 'A';

    int a = fib[i-2];
    return a <= n ?  fib_w(n,i-2) : fib_w(n-a,i-1);
}

int32_t main(){
    int n,x; cin>>n;
    fib.push_back(0);fib.push_back(1);
    for(int i=2;i<89; i++)
        fib.push_back(fib[i-1]+fib[i-2]);
    while(n--){
        cin>>x;
        auto k = lower_bound(fib.begin(),fib.end(),x);
        int i = k - fib.begin();

        if(fib_c(x,i) == fib_w(x,i)){
            //cout<<fib_c(x,i)<<" "<<fib_w(x,i)<<endl;
            continue;
        }
        else{
            cout<<"WA\n"; 
            return 0;
        }
    }
    cout<<"AC\n";
}