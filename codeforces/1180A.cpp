#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, tmp = 4;
    cin>>n;
    vector<int> arr(n+1,0);
    arr[0] = 1;

    for(int i=1; i<n; i++){
        arr[i] = arr[i-1] + tmp;
        tmp += 4;
    }

    cout<<arr[n-1]<<endl;
}