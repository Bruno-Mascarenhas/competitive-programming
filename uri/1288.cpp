#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[101][100010], w[101], val[101],n,cap,target,t;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>val[i]>>w[i];
        cin>>cap>>target;
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

        if(dp[n][cap]>=target) cout<<"Missao completada com sucesso\n";
        else cout<<"Falha na missao\n";
    }
}