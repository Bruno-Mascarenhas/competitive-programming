  #include <bits/stdc++.h>
  using namespace std;
  #define int long long
  #define bit(x,i) (x&(1<<i))
  //#define size(x) ((int)((x).size()))
  #define pi 3.1415926535897932384626
  #define pb push_back
  #define ff first
  #define ss second
  #define debug(x) cout << #x " = " << (x) << endl
  #define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
  #define endl '\n'
  #define EPS 1e-9
  #define INF 1e18
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

  int32_t main(){
    DESYNC;
    int id[] = {0,1,2,0,2,1,0}; vi arr(3);
    cin>>arr[0]>>arr[1]>>arr[2];
    int maxi = min({arr[0]/3,arr[1]/2,arr[2]/2});
    arr[0] -= maxi * 3;
    arr[1] -= maxi * 2;
    arr[2] -= maxi * 2;

    int start, ans=0;
    for(start = 0; start<7; start++){
      int curr=0, day = start; vi tmp = arr;
      while(tmp[id[day]]>0){
        tmp[id[day]]--;
        day = (day+1)%7;
        curr++;
      }
      ans = max(ans,maxi*7 + curr);
    }
    cout<<ans<<endl;
    return 0;
  }