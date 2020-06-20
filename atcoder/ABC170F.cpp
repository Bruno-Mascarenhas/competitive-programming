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
#define ALL(x) for(int i=0; i<x; i++)
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

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

int fpow(int x, unsigned int y, int p){ 
    int res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
} 
const int maxn = (int)1e6+100;

int h,w,k,x1,x2,y11,y2;

bool valid(vector<vector<char>> grid, int x, int y){
    if(x < h && x >= 0 && y < w && y >= 0)
        return grid[x][y] != '@';
    return false;
}

vector<vector<long double>> dijkstra(vector<vector<char>> grid){
    vector<vector<long double>> dist(h,vector<long double>(w,INF));

    priority_queue<pair<long double,pii>, vector<pair<long double,pii>> , greater<pair<long double,pii>>> pq;

    dist[x1][y11] = 0;

    pq.push({0,{x1,y11}});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        long double d = cur.first;
        pii coord = cur.second;

        if(d > dist[coord.ff][coord.ss]) continue;

        for(int i=0; i<4; i++){
            if(valid(grid,coord.ff+dx[i],coord.ss+dy[i])){
                int nx = coord.ff + dx[i], ny = coord.ss + dy[i];
                if(dist[coord.ff][coord.ss] + 1/(long double)k < dist[nx][ny]){
                    dist[nx][ny] = dist[coord.ff][coord.ss] + 1/(long double)k;
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
    }

    return dist;
}

int32_t main(){
	DESYNC;
    cin>>h>>w>>k>>x1>>y11>>x2>>y2;
    x1--; x2--; y11--; y2--;

    vector<vector<char>> grid(h,vector<char>(w));


    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>grid[i][j];

    auto dist = dijkstra(grid);

    cout<<(dist[x2][y2] < INF ? ceil(dist[x2][y2]) :-1)<<endl;
}