#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d; string s;
    cin>>n>>d>>s;

    vector<int> dp(n+10, 1000);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int tmp = 1000;
        for(int j = max(0,i-d); j<i; j++)
            if(s[j] == '1')
                tmp = min(tmp,dp[j]);
        dp[i] = min(dp[i],tmp+1);
    }

    cout<<(dp[n-1]== 1000 ? -1 : dp[n-1])<<endl;
}