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
#define int long long

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

int32_t main(){
    DESYNC;
    int a, b, qtd;
    cin>>a>>b;

    while(a!=0 && b!=0){
        if(a >= 2LL*b){
            qtd = (a/b)/2;
            a -= 2LL*b*qtd;
        } else if(b >= 2LL*a){
            qtd = (b/a)/2;
            b -= 2LL*a*qtd;
        } else break;
    }

    cout<<a<<" "<<b<<endl;
}