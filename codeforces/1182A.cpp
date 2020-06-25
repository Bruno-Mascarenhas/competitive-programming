#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    long long ans;
    cin>>n;
    if(n%2) 
        ans = 0;
    else 
        ans = pow(2,n/2);

    cout<<ans<<endl;
}