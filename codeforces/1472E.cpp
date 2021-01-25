//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <functional>
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
//Compilation flags // g++ -std=c++17 -O2 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g 
const int maxn = 2e5+10;
int n;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    int h,h2,w,w2,id,id2;
    tie(h,w,id) = a;
    tie(h2,w2,id2) = b;

    if(h!=h2) return h < h2;
    else return w > w2;
}

void testcase(){
    cin>>n;
    vector<tuple<int,int,int>> arr(n);
    vector<int> ans(n, -1);
    
    for(int i=1; i<=n; i++){
        int h, w; cin>>h>>w;
        if(w > h) swap(h,w);
        arr[i-1] = {h,w,i};
    }
 
    sort(arr.begin(), arr.end(), cmp);

    pii mn = {1e9+5,-1};
    for(int i=0; i<n; i++){
        int h,w,id;
        tie(h,w,id) = arr[i];
        
        if(mn.first < w) ans[id-1] = mn.second;
        if(w < mn.first) mn = {w,id};
    }
 
    for(int &x: ans) cout<<x<<" ";
    cout<<endl;
}
 
int32_t main(){
    DESYNC;
    int t; cin>>t;
    while(t--) testcase();
}