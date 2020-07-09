#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;

int mod(int n, int m = MOD){
    n %= m;
    return n < 0 ? n+m : n;
}

signed main(){
    int n, k, ans = 1;
    cin>>n>>k;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin>>arr[i];

    sort(arr.begin(), arr.end());

    if(arr[0]>=0){
        for(int i=0; i<k; i++) ans = mod(arr[n-1-i]*ans);
        return cout<<ans<<endl, 0;
    } else if(arr[n-1] <= 0){
        for(int i=0; i<k; i++) ans = mod(ans * arr[(k % 2 ? n - 1 - i : i)]);
        return cout<<ans<<endl, 0;
    }

    int l=0, r=n-1, xl, xr;
    if(k%2){
        ans = mod(ans*arr[r]);
        r--, k--;
    }

    while(k > 0){
        xl = arr[l] * arr[l+1];
        xr = arr[r] * arr[r-1];

        if(xl >= xr){
            ans = mod(ans * mod(xl));
            l+=2;
        } else{
            ans = mod(ans * mod(xr));
            r-=2;
        }
        k-=2;
    }
    cout<<ans<<endl;
}