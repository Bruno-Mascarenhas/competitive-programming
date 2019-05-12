#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;
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
#define all(x) for(int i=0; i<x; i++)
#define fori(a,b,c) for(int a=b; a<c; a++)
#define present(c,x) ((c).find(x) != (c).end())
#define m0(x) memset((x), 0, sizeof(x))
#define m1(x) memset((x), -1, sizeof(x))
#define ok printf("ok\n")
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

int bit[1010][1010],n,q,op,x,y,x2,y2,val,m;

void update(int x, int y, int val){
    for(;x<=1010;x+=x&-x)
        for(int y1=y;y1<=1010;y1+=y1&-y1)
            bit[x][y1]+=val;
}

int sum(int x, int y){
    int ans = 0;
    for(;x>0;x-=x&-x)
        for(int y1=y;y1>0;y1-=y1&-y1)
            ans+=bit[x][y1];
    return ans;
}

int query(int x1, int y1, int x2, int y2){
    int a = sum(x2,y2);
    int b = sum(x2,y1-1);
    int c = sum(x1-1,y2);
    int d = sum(x1-1,y1-1);
    return a - b - c + d;
}

int32_t main(){
    DESYNC;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            cin>>x;
            update(j,i,x);
        }
    cin>>q;
    while(q--){
        cin>>op;
        if(op){
            cin>>x>>y>>val;
            update(x,y,val);
        }
        else{
            cin>>x>>y>>x2>>y2;
            cout<<query(x,y,x2,y2)<<endl;
        }
    }
}


