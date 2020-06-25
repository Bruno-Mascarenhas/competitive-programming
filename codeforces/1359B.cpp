#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;
int t, n, m, x, y;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>x>>y;
        vector<int> arr(m+2,1);
        string s;
        int ans = 0;

        y = min(y,x*2);

        for(int l=0; l<n; l++){
            cin>>s;
            vector<int> dp(m+1, 1000*1005);
            for(int i=0; i<m; i++)
                s[i] == '.' ? arr[i] = 1 : arr[i] = 0;

            dp[0] = 0;
            for(int i=0; i<m; i++){
                if(s[i] == '*') dp[i+1] = dp[i];
                else{
                    dp[i+1] = dp[i] + x;
                    if(i && s[i-1] == '.') dp[i+1] = min(dp[i+1],dp[i-1]+y);
                }
            }
            
            ans += dp[m];
        }
        cout<<ans<<endl;    
    }
}