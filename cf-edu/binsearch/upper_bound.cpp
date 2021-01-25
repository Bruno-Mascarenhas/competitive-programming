#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int &x: arr) cin>>x;

    while(q--){
        int l=-1, r = n, x;
        cin>>x;

        while(r > l+1){
            int mid = (l+r)/2;
            if(arr[mid] >= x) r = mid;
            else l = mid;
        }

        cout<<r+1<<endl;
    }

}