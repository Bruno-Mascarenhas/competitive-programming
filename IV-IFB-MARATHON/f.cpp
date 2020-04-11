#include <bits/stdc++.h>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
//#define int long long
using namespace std;
const int maxn = 1e4+10;

int arr[maxn], dp[maxn][maxn], w[maxn],n,cap;

int32_t main(){
    DESYNC;
    cin>>n>>cap;

    for(int i=0; i<n; i++)
        cin>>w[i];
    
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for (int i = 0; i <= n; i++){ 
        for (int p = 0; p <= cap; p++){ 
            if (i==0 || p==0) 
                dp[i][p] = 0; 
            else if (arr[i-1] <= p) 
                dp[i][p] = max(w[i-1] + dp[i-1][p-arr[i-1]],  dp[i-1][p]); 
            else
                dp[i][p] = dp[i-1][p]; 
       } 
   } 
  
   cout<<dp[n][cap]<<endl;        
}