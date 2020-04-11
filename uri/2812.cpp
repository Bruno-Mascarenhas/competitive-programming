#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        deque<int> arr;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x&1) arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        int i=1;
        while(!arr.empty()){
            if(i&1){
                cout<<arr.back()<<(arr.size()>1?" ":"");
                arr.pop_back(), i^=1;
            }
            else{
                cout<<arr.front()<<(arr.size()>1?" ":"");
                arr.pop_front();
                i^=1;
            }
        }
        cout<<endl;
    }
}