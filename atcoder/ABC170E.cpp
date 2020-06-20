#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
#define bit(x,i) (x&(1<<i))
#define pi 3.1415926535897932384626
#define pb push_back
#define pf push_front
#define mt make_tuple
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define EPS 1e-9
#define INF 1e18
#define ALL(x) for(int i=0; i<x; i++)
#define fori(a,b,c) for(int a=b; a<c; a++)
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define m0(x) memset((x), 0, sizeof(x))
#define m1(x) memset((x), -1, sizeof(x))

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

int fpow(int x, unsigned int y, int p){ 
    int res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
} 
const int maxn = 2e5+20;
const int inf = (int)10e9;

int belong[maxn], rating[maxn];
multiset<pii> total;
multiset<pii,greater<pii>> kindergartens[maxn];
unordered_set<int> valids;

void del(int kind, int child){
    auto it = kindergartens[kind].find({rating[child],child});
    bool add = false;

    if(it != kindergartens[kind].end()){
        if(it == kindergartens[kind].begin()){
            auto it2 = total.find({rating[child],child});
            if(it2 != total.end()) total.erase(it2), add = true;
        }
        kindergartens[kind].erase(it);

        if(add && kindergartens[kind].size()>0) total.insert(*kindergartens[kind].begin());
    }
}

void push(int kind, int child){
    if(kindergartens[kind].size() > 0){
        auto it = total.find(*kindergartens[kind].begin());
        if(it!= total.end()) total.erase(it);
    }

    kindergartens[kind].insert({rating[child],child});

    total.insert(*kindergartens[kind].begin());
}

int32_t main(){
	DESYNC;
    int n, q, a, b, c, d;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        cin>>a>>b;
        rating[i] = a;
        belong[i] = b;
        kindergartens[b].insert({a,i});
        valids.insert(b);
    }

    for(int x: valids)
        total.insert(*kindergartens[x].begin());

    for(int i=0; i<q; i++){
        cin>>c>>d;

        int tmp = belong[c];
        belong[c] = d;

        del(tmp,c);
        push(d,c);
        
        cout<<total.begin()->first<<endl;        
    }
}