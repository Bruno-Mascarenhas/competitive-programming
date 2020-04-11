#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

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
const int maxn = 2e5+10;

int bit[maxn], n, pot[maxn];

void update(int i, int val){
    for(;i<=n;i+=i&-i)
        bit[i]+=val;
}

int sum(int i){
    int ans = 0;
    for(;i;i-=i&-i) ans+=bit[i];
    return ans;
}

int query(int a, int b){
    return sum(b) - sum(a-1);
}

int32_t main(){
    string op; int l, r, x, test = 1;
    while(cin>>n && n){
        m0(bit);
        for(int i=1; i<=n;i++){
            cin>>pot[i];
            update(i,pot[i]);
        }
        printf("Case %d:\n",test++);
        while(cin>>op && op[0]!='E'){
            cin>>l>>r;
            if(op[0] == 'S'){
                int diff = r - pot[l];
                pot[l]=r;
                update(l,diff);
            }
            else cout<<query(l,r)<<endl;
        }
        cout<<endl;   
    }
}