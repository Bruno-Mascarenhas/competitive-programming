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

const int maxn = 3*1e5+10;

int32_t main(){
    DESYNC;
    int n; cin>>n;
    int ans = 0, x;
    set<int> segments;
    segments.insert(0);

    int tmp = 0;
    for(int i=0; i<n; i++){
        cin>>x;
        if(segments.count(tmp + x)){
            ans++;
            tmp = 0;
            segments.clear();
            segments.insert(0);
        }
        tmp += x;
        segments.insert(tmp);
    }

    cout<<ans<<endl;

}