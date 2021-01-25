#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define mt make_tuple
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << " "
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define EPS 1e-9
#define INF 1e18

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

const int maxn = 3*1e5+10;

int main(){
    DESYNC;
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        bool hassym = 0;
        vector<vector<int>> arr(n, vector<int> (4));// 0 == 3, 1 == 2
        for(auto it: arr){
            cin>>it[0]>>it[1]>>it[2]>>it[3];
            hassym |= (it[1] == it[2]);
        }


        if(m%2!=0){ cout<<"NO\n"; continue; }

        cout<<((hassym) ? "YES":"NO")<<endl;
        //debug(n); debug(m); cout<<endl;
    }
}