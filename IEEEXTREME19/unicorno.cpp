#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 3.1415926535897932384626
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;

vii coords; vector<pair<int,pii>> power;
int n,m,s;
bool solve(int mid){
    for(int i=0; i<mid; i++){
        
    }
}

int main(){
    int n,m,s;
    for(int i=0; i<m; i++){
        int a,b;
        coords.pb({a,b});
    }
    for(auto &x: coords) cin>>x.ff>>x.ss;
    power.resize(m); //custo x coords
    for(auto x:power) cin>>x.ff>>x.ss.ff>>x.ss.ss;
    int ans = 1e9, l=0, r=s, mid;
    sort(power.begin(),power.end());
    while(l<=r){
        mid = l+r>>1;
        if(solve(mid))
            r = mid-1;
        else
            l = mid;
    }

}