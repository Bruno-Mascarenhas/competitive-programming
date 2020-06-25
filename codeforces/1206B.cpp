#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, ans = 0, test = 1, zero = 0;
    cin>>n;

    vector<int> arr(n);
    for(int &x: arr) cin>>x;

    for(int i=0; i<n; i++){
        zero |= (arr[i] == 0);
        if( abs(-1-arr[i]) < abs(1-arr[i]) ){
            ans += abs(-1 - arr[i]);
            arr[i] += -1 - arr[i];
        } else {
            ans += abs(1 - arr[i]);
            arr[i] += 1-arr[i];
        }
    }

    for(int x: arr) test *= x;
    if(test == -1) zero ? ans=ans : ans+=2;
    cout<<ans<<endl;
    
    //for(int x: arr) cout<<x<<" ";    cout<<endl;

}