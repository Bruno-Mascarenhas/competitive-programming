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
#define for0(x) for(int i=0; i<x; i++)
#define ALL(x) a.begin(),a.end()
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

int32_t main(){
    DESYNC;
    int n; string s;
    cin>>n>>s;

    map<string,int> freq;

    for(int i=0; i<n-1; i++)
        freq[s.substr(i,2)]++;

    pair<int, string> ans;

    for(auto it: freq)
        ans = max(ans,{it.ss,it.ff});

    cout<<ans.ss<<endl;
}