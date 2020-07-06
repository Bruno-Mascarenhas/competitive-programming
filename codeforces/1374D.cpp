#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#define int long long
using namespace std;


int maxi(int &a, int b){
    a = max(a,b);
    return a;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;

    while(t--){
        int n, k, x, ans = 0, tmp;
        cin>>n>>k;

        unordered_map<int,int> cnt;
        cnt.reserve(1LL<<(int)log2(n));
        cnt.max_load_factor(0.25);

        for(int i=0; i<n; i++){
            cin>>x;
            tmp = k - (x%k);
            if(!(x%k)) continue;
            if(cnt[tmp]) cnt[tmp] += k;
            else cnt[tmp] = tmp;
        }

        for(auto [key, value]: cnt)
            ans = maxi(ans,value+1);
        
        cout<<(cnt.size()? ans : 0)<<endl;
    }

}