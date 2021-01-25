#include <bits/stdc++.h>
using namespace std;

int upper_bound(vector<int> &arr, int n, int x){
    int l=-1, r = n;

    while(r > l+1){
        int mid = (l+r)/2;
        if(arr[mid] >= x) r = mid;
        else l = mid;
    }
    return r;
}

int lower_bound(vector<int> &arr, int n, int x){
    int l=-1, r = n;

    while(r > l+1){
        int mid = (l+r)/2;
        if(arr[mid] > x) r = mid;
        else l = mid;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n;
    vector<int> arr(n);
    for(int &x: arr) cin>>x;
    sort(arr.begin(), arr.end());

    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;

        cout<<lower_bound(arr, n, r) - upper_bound(arr, n, l)+1<<" ";
    }
}