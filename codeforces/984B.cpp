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

char mat[101][101];
int n, m;

bool valid(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m)
        return false;
    return true;
}

bool check(int x, int y, int qtd){
    int bombs = 0;
    for(int i=0; i<8; i++)
        if(valid(x+dx[i],y+dy[i]) && mat[x+dx[i]][y+dy[i]]=='*')
            bombs++;

    return bombs == qtd;
}

int32_t main(){
    DESYNC;
    cin>>n>>m;

    bool ok = true;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(mat[i][j] != '*'){
                int dig;
                dig = (mat[i][j] == '.' ? 0 : mat[i][j]-'0');
                if(!check(i,j,dig)) ok = false;
            }

    cout<<(ok ? "YES":"NO")<<endl;
}