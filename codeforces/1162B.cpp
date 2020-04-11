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
int a[55][55],b[55][55],n,m;

int32_t main(){
    DESYNC;
    cin>>n>>m;
    fori(i,0,n)
        fori(j,0,m)
            cin>>a[i][j];

    fori(i,0,n)
        fori(j,0,m){
            cin>>b[i][j];
            if(a[i][j] < b[i][j])
                swap(a[i][j],b[i][j]);
        }
    //matA vs matB
    int f = 1;
    fori(i,0,n)
        fori(j,0,m){
            if(i && a[i-1][j]>=a[i][j]) f = 0;
            if(j && a[i][j-1]>=a[i][j])f = 0; 

            if(i && b[i-1][j]>=b[i][j]) f = 0;
            if(j && b[i][j-1]>=b[i][j]) f = 0;
        }

    f?cout<<"Possible\n":cout<<"Impossible\n";

}