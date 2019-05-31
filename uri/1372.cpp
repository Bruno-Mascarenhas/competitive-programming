#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int n,m, mat[N][N], dp[N][N];
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>m>>n && n+m>0){
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(i==0)
                    dp[i] = 

    }
}