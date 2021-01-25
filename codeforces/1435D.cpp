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
    int n, flag=1, cnt = 0, x;
    cin>>n;
    set<int> nums;
    deque<int> ans;

    vector<pair<char,int>> ops;
    for(int i=0; i<2*n; i++){
        char op; cin>>op;
        if(op == '-') cin>>x, cnt--;
        else cnt++;
        if(cnt < 0) flag = 0;

        ops.push_back({op, (op=='+'?0:x)});
    }

    reverse(ops.begin(), ops.end());
    
    for(auto el: ops){
        char op = el.first; int num = el.second;
        if(op == '-'){ 
            if(nums.size()>0 && *nums.begin() < num) flag = 0;
            nums.insert(num);
        }
        else {
            if(nums.size() == 0) flag = 0;
            else ans.push_back(*nums.begin()), nums.erase(nums.begin());
        }
    }



    if(!flag) cout<<"NO\n";
    else {
        reverse(ans.begin(), ans.end());
        cout<<"YES\n";
        for(int el: ans) cout<<el<<" ";
        cout<<endl;
    }
}