#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

signed main(){
    DESYNC;
    int t;
    cin>>t;
    while(t--){
        int a,b,c, na, nb, nc, ans = INT_MAX, bigg = 20020;
        cin>>a>>b>>c;

        for(int i = 1; i<=bigg; i++)
            for(int j = 1; j<=bigg/i; j++)
                for(int k = 1; k<=bigg/i/j; k++){
                    int tmp = abs(i-a) + abs(i*j-b) + abs(i*j*k-c);
                    if(tmp < ans){
                        ans = tmp;
                        na = i; nb = j*i; nc = k*i*j;
                    }
                }
        cout<<ans<<endl<<na<<" "<<nb<<" "<<nc<<endl;
    }
}