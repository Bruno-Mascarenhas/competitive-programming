#include <iostream>
#include <vector>
#define endl "\n"
#define debug(x) cout << #x " = " << (x) << endl
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);

    for(int &x: arr) cin>>x;
    
    int ans=0;
    for(int i=0; i<n && arr[i]<=k;i++) ans++;
    for(int i=n-1; i>=0 && arr[i]<=k;i--) ans++;

    cout<<min(ans,n)<<endl;
}