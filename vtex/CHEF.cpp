#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define int long long
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

bool compis(pair<pii,pii> a, pair<pii,pii> b){
    return a.ff.ss < b.ff.ss;
}

int32_t main(){
    DESYNC;
    int n, k, tA=0, tB=0; queue<int> A, B;
    cin>>n>>k;
    vector<pair<pii,pii>> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i].ff.ff>>arr[i].ss.ff;
        arr[i].ff.ss = i;
    }
    sort(arr.begin(),arr.end());
    map<pair<pii,pii>,char> mapa;
    //cout<<endl<<endl;
    //for(auto x : arr) cout<<x.ff.ff<<" "<<x.ff.ss<<" "<<x.ss.ff<<endl;
    for(int i=0; i<n; i++){
        int tempo = arr[i].ff.ff;
        while(!A.empty()){
            if(A.front() <= tempo) A.pop();
            else break;
        }
        while(!B.empty()){
            if(B.front() <= tempo) B.pop();
            else break;
        }

        if(A.size() <= B.size()){
            if(tA < arr[i].ff.ff) tA = arr[i].ff.ff+arr[i].ss.ff;
            else tA+=arr[i].ss.ff;
            arr[i].ss.ss = tA;
            mapa[arr[i]] = 'A';
            A.push(tA);
        }
        else{
            if(tB < arr[i].ff.ff) tB = arr[i].ff.ff+arr[i].ss.ff*k;
            else tB+=arr[i].ss.ff * k;
            arr[i].ss.ss = tB;
            mapa[arr[i]] = 'B';
            B.push(tB);
        }
    }

    sort(arr.begin(),arr.end(),compis);
    for(auto x: arr)
        cout<<mapa[x]<<" "<<x.ss.ss<<endl;

}


