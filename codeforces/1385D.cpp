#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

const int maxn = 131072;
string s; int n;

int f(int l, int r, int chr){
    if(l == r) return s[l] != chr;

    int c1=0, c2=0;
    for(int i=l; i<=(l+r)/2; i++)
        c2+= (s[i] != chr);
    for(int i=(l+r)/2+1; i<=r; i++)
        c1+= (s[i] != chr);
    
    return min(f(l,(l+r)/2,chr+1)+c1,f((l+r)/2+1,r,chr+1)+c2);
}

int32_t main(){
    DESYNC;
    int t; cin>>t;
    while(t--){
        cin>>n>>s;
        cout<<f(0,n-1,'a')<<endl;
    }

}