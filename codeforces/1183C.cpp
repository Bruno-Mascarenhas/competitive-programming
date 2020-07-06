#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int k, n, a, b, t, maxturns, ans;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>k>>n>>a>>b;
        //n = turns of game || k = initial battery //
        if(n*b >= k){
            cout<<-1<<endl;
            continue;
        } else {
            //do binary search on A
            int l = 1, r = n, mid;
            ans = 0;
            while(l <= r){
                mid = (l+r)>>1;
                if(mid*a + (n-mid)*b < k){
                    ans = mid;
                    l = mid+1; 
                }
                else 
                    r = mid-1;
            }
            cout<<ans<<endl;
        }
    }
}
/*
6
15 5 3 2
15 5 4 3
15 5 2 1
15 5 5 1
16 7 5 2
20 5 7 3
*/