#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int x,y,n;
        cin>>x>>y>>n;

        cout<< (n-y)/x * x + y <<endl;

    }
}