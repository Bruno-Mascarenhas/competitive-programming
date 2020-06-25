#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, t, s, d;
    cin>>n>>t;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>s>>d;
        while(s < t) s+=d;
        arr[i] = s;
    }

    pair<int,int> ans = {INT_MAX,0};
    for(int i=0; i<n; i++)
        if(abs(t - arr[i]) < ans.first)
            ans = {abs(t-arr[i]),i};
    
    cout<<ans.second+1<<endl;
}