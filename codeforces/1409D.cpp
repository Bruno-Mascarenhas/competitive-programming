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

int sum(int n){
    int ans = 0;
    while(n > 0){
        ans += n%10;
        n /= 10;
    }  
    return ans;
}

void add(int &n, int &ans, int &power){
    int digit = (n/power)%10;

    int tmp = ((10-digit)%10)*power;

    n += tmp;
    ans += tmp;
    power *= 10;
}

int32_t main(){
    DESYNC;
    int t; cin>>t;
    while(t--){
        int n, s, ans = 0;
        cin>>n>>s;

        if(sum(n) <= s){ cout<<0<<endl; continue;}

        int power = 1;
        for(int i=0; i<18; i++){
            add(n,ans,power);

            if(sum(n) <= s) break;
        }

        cout<<ans<<endl;
    }
}