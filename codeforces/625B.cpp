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

int32_t main(){
    DESYNC;
    string s, pat; cin>>s>>pat;

    int ans=0, n = pat.size()-1, i = s.find(pat);

    while(i != string::npos || i < s.size()){
        s[i+n] = '#';
        i+=n;
        ans++;
        i = s.find(pat,i);
    }

    cout<<ans<<endl;

}