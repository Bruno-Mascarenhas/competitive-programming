#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, ans=0;
    cin>>n>>k;
    vector<int> arr(n);

    for(int &x: arr) cin>>x;

    for(int i=1; i<n; i++){
        if(arr[i-1]+ arr[i] < k){
            ans += k - (arr[i-1]+ arr[i]);
            arr[i] += k - (arr[i-1]+ arr[i]);
        }
    }

    cout<<ans<<endl;
    for(int x: arr) cout<<x<<" ";
    cout<<endl;
}