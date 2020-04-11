#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[101][100010], w[101], val[101],n,cap;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n && n){
        cin>>cap;
        for(int i=0; i<n; i++)
            cin>>val[i]>>w[i];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=cap; j++){
                if(j == 0 || i == 0)
                    dp[i][j] = 0;
                else if(w[i-1] <= j){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+val[i-1]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        cout<<dp[n][cap]<<" min."<<endl;
    }
}