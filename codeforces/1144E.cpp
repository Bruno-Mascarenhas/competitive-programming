#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bit(x,i) (x&(1<<i))
//#define size(x) ((int)((x).size()))
#define pi 3.1415926535897932384626
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define EPS 1e-9
#define INF 1e18
#define td(x) x.begin(),x.end()
#define ALL(x) for(int i=0; i<x; i++)
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define m0(x) memset((x), 0, sizeof(x))
#define m1(x) memset((x), -1, sizeof(x))

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;

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
int32_t maxn = 2e5+10;
int n, carry;string a,b;
vi sum,last;
int32_t main(){
	DESYNC;
	cin>>n>>a>>b;
  reverse(td(a));  reverse(td(b));
  int tmp;
  for(int i=0; i<n; i++){
    tmp = (a[i]-'a')+(b[i]-'a')+carry;
    sum.pb(tmp%26);
    carry = tmp/26;
  }
  sum.pb(carry);
  reverse(td(sum));carry=0;
  for(int i=0; i<sum.size(); i++){
    last.pb((carry*26 + sum[i])/2);
    carry = (carry*26+sum[i])%2;
  }
  //pos f = carry
  for(int i=1; i<last.size();i++)
    cout<<(char)(last[i]+'a');
  cout<<endl;

}