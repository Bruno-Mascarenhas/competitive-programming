#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
vector<int> factorize(int n){
    vector<int> factors(1);
    factors[0] = 1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            factors.pb(i);
            if(i != n/i) factors.pb(n/i);
        }
    }
    return factors;
}
int32_t main(){
    int n,m;
    cin >> n >> m;
    set<pii> seg;
    int mov = 0;
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(b < a){
            swap(b,a);
        }
        b--;
        a--;
        seg.insert(pii(a,b));
    }
    vector<int> f = factorize(n);

    bool ok = false;
    for(int x : f){
        ok = true;
        for(pii y : seg){
            pii now = pii(mod(y.ff + x,n),mod(y.ss + x,n));
            if(now.ff > now.ss) swap(now.ff,now.ss);
            cout<<now.ff<<" "<<now.ss<<"====="<<y.ff<<" "<<y.ss<<" "<<x<<endl;
            if(!seg.count(now)){
                ok = false;
                break;
            } 
        }
        if(ok) break;
    }
    cout << ( ok ? "yes" : "no") << endl;
} 