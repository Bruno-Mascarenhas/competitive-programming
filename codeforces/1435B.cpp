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

int32_t main(){
    DESYNC;
    int t, n, m; cin>>t; 
    while(t--){
        cin>>n>>m;

        map<int,vector<int>> row;

        for(int i=0; i<n; i++){
            vector<int> rowi(m);
            for(int &x: rowi) cin>>x;
            row[rowi.front()] = rowi;
        }

        int flag = 0, x;
        for(int i=0; i<m; i++){
            if(!flag){
                for(int j=0; j<n; j++){
                    cin>>x; if(row.count(x)) flag = 1;
                    if(flag) for(int el: row[x]) cout<<el<<" ";
                    if(flag) cout<<endl;
                }
            } else {
                for(int j=0; j<n; j++) cin>>x;
            }
        }
    }
}