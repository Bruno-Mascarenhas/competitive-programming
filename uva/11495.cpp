#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define m0(x) memset(x,0,sizeof(x))
#define int long long
const int maxn = 2e5+10;
int bit[maxn],n,arr[maxn],ans,maxi;

void update(int i, int lim){
    for(;i<=lim;i+=i&-i)
        bit[i]++;
}

int query(int i){
    int ans =0;
    for(;i>0;i-=i&-i)
        ans+=bit[i];
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    while(cin>>n && n){
        ans=0; m0(bit);maxi=0;
        for(int i=1; i<=n;i++){
            cin>>arr[i];maxi = max(arr[i],maxi);}
        for(int i=n; i>0; i--){
            ans+=query(arr[i]-1);
            update(arr[i],maxi);
        }
        ans%2!=0?cout<<"Marcelo\n":cout<<"Carlos\n";
    }
}