#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, t, x, y, ans = INT64_MAX;
    cin>>n>>k;   
    vector<int> both, a, b;
    for(int i=0; i<n; i++){
        cin>>t>>x>>y;
        if(x && y)
            both.push_back(t);
        else if(x) a.push_back(t);
        else if(y) b.push_back(t); 
    }
    a.push_back(0); b.push_back(0); both.push_back(0);

    sort(both.begin(), both.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=1; i<(int)both.size(); i++) both[i] += both[i-1];
    for(int i=1; i<(int)a.size(); i++) a[i] += a[i-1];
    for(int i=1; i<(int)b.size(); i++) b[i] += b[i-1];

    for (int i = 0; i < min(k+1, (int)both.size()); i++)
        if( (k - i) < (int)a.size() && (k - i) < (int)b.size())
            ans = min(ans, both[i] + a[k - i] + b[k - i]);
    
    cout<<(ans == INT64_MAX ? -1 : ans)<<endl;   
}