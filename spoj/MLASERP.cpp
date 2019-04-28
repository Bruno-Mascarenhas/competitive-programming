#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.1415926535897932384626
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define ALL(x) for(int i=0; i<x; i++)

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;
const int maxn = 101, INF = 0x3f3f3f3f;
int n,m, mat[maxn][maxn][4]; char arr[maxn][maxn];
pii start, dest;

bool valid(int a, int b){
    if(a<m && a>=0 && b<n && b>=0)
        if(arr[a][b]!='*')
            return true;
    return false;
}

void bfs(){
    memset(mat,INF,sizeof mat);
    deque<pair<int,pii>> q;
    for(int i=0; i<4; i++){
        mat[start.ff][start.ss][i] = 0;
        q.pb({i,start});
    }
    int value;
    while(!q.empty()){
        auto curr = q.front(); q.pop_front();
        int dir = curr.ff;
        pii from = curr.ss;

        for(int i=0; i<4; i++){
            dir == i ? value = 0 : value = 1;
            pii to = {from.ff+dx[i],from.ss+dy[i]};
            if(valid(from.ff,from.ss) && mat[from.ff][from.ss][dir]+value < mat[to.ff][to.ss][i]){
                mat[to.ff][to.ss][i] = mat[from.ff][from.ss][dir]+value;
                value ? q.pb({i,to}) : q.pf({i,to});
            }
        }
    }
}

int32_t main(){
    DESYNC; bool f = 0;
    cin>>m>>n;
    for(int i=0; i<m; i++) 
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'C'){
                if(!f)
                    start = {i,j}, f=1;
                else
                    dest = {i,j}; 
            }   
        }

    bfs();
    int ans = INF;
    for(int i=0;i<4;i++)
        ans = min(ans,mat[dest.ff][dest.ss][i]);
    cout<<ans<<endl;
}