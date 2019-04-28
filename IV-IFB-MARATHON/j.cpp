#include <bits/stdc++.h>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
using namespace std;
#define EPS 1e-9
typedef long double ld;

int32_t main(){
    DESYNC; int n; ld ans=0, diff;
    cin>>n;
    vector<ld> arr(n);
    for(ld &i:arr) cin>>i;

    sort(arr.begin(),arr.end());
    
    (n%2==0) ? diff = (arr[n/2] + arr[n/2-1])/2 : diff  = arr[n/2];
 
    for(int i=0; i<n; i++)
        ans+=fabs(arr[i]-diff);

    cout<<fixed<<setprecision(10)<<ans<<endl;

}