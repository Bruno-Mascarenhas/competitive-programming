#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = 1, tmp = 1;
    cin>>n;
    
    vector<int> arr(n); 
    for(int &x: arr) cin>>x;

    for(int i=1; i<n; i++){
        if(arr[i] >= arr[i-1])
            tmp++;
        else
            ans = max(tmp, ans), tmp = 1;
    }

    cout<<max(tmp,ans)<<endl;
}