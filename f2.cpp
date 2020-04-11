#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin>>n;

    vector<int> arr(n+2);
    map<int,int> dp;
    stack<int> ans;
    int big=0, val=0;

    for(int i=1; i<=n; i++){
        cin>>x;
        arr[i] = x;
        dp[x] = max(dp[x],dp[x-1]+1);
        if(dp[x] > big){
            big = dp[x];
            val = x;
        }
    }

    cout<<big<<endl;
    for(int i=n; i>=1; i--)
        if(arr[i] == val) ans.push(i), val--;

    while(!ans.empty()) cout<<ans.top()<<" ", ans.pop();
    cout<<endl;

}