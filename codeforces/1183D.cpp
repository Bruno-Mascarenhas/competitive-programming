#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define int long long
using namespace std;

int n, t, tmp, ans;
const int maxn = 2e5+100;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> freq(n+2,0);

        for(int i=0; i<n; i++){
            cin>>tmp;
            freq[tmp]++;
        }

        sort(freq.rbegin(),freq.rend());
        ans = 0, tmp = INT32_MAX;

        for(int i=0; i<n; i++){
            if(!freq[i]) break;

            if(freq[i] >= tmp){
                tmp -= 1;
                tmp = max(0LL,tmp);
                ans += tmp;
            } else {
                tmp = freq[i];
                ans += tmp;
            }
        }

        cout<<ans<<endl;
    }
}
