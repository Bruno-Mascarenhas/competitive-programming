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

const int dx[] = {0,1,0,-1,-1,1,-1,1};
const int dy[] = {1,0,-1,0,-1,1,1,-1};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

int compute(string a, string b){
    int ans = 0, n  = a.size(), len = 0;
    for(int i=0; i<n; i++)
        if(a[i] == b[i]) ans += len, len=0;
        else len=1;
    return ans+len;
}

int32_t main(){
    DESYNC;
    int t, n; string s; cin>>t;
    while(t--){
        cin>>n>>s;
        string a(n,'0'), b(n,'0');

        for(int i=0; i<n; i++)
            if(i%2 == 0) a[i] = '1';
            else b[i] = '1';

        cout<<min(compute(s,a),compute(s,b))<<endl;
    }
}