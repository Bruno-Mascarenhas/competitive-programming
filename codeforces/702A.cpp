#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, ans = 0, tmp = 0;
    cin>>n;
    int arr[n+1];

    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i && arr[i] > arr[i-1])
            tmp++;
        else{
            ans = max(ans,tmp);
            tmp = 1;
        }
    }
    cout<<max(tmp,ans)<<endl;
}