#include <bits/stdc++.h>
//#define int long long
#define ff first
#define ss second
using namespace std;
const int M = 1e9+7, MAXX = 5e5+10;
int mod(int n){ n%=M; return n<0?n+=M:n;}
int bit[2][MAXX], n, ans;
vector<pair<int,int>> arr;

void update(int f, int i, int val){
    for(;i<=n; i+=i&-i)
        bit[f][i] = mod(bit[f][i]+val);
}

int sum(int f, int i){
    int ans=0;
    for(;i>0;i-=i&-i)
        ans = mod(ans+bit[f][i]);
    return ans;
}

int query(int f, int l, int r){
    return mod(sum(f,r) - sum(f,l-1));
}


int32_t main(){
    cin>>n;
    arr.resize(n);
    for(int i=1; i<=n; i++){
        cin>>arr[i].ff;
        arr[i].ss = i;
    }
    sort(arr.begin(),arr.end());

    int lquery, rquery, posum;
    for(int i=0; i<n; i++){
        int val = arr[i].ff, pos = arr[i].ss;
        int qtd = n - arr[i].ss + 1; 
        lquery = mod(query(0,1,pos) * qtd);
        rquery = mod(query(1,pos,n) * qtd);
        posum = mod(val * qtd);
        ans = mod(mod(mod(mod(ans)+lquery)+rquery)+posum);
        update(0,pos,pos);
        //update(1,pos,qtd);
    }
    cout<<ans<<endl;
}