#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, ans = 0;
    cin>>n;

    vector<int> coins = {1, 5, 10, 20, 100};

    for(int i=4; i>=0; i--){
        ans += n/coins[i];
        n %= coins[i];
    }

    cout<<ans<<endl;
}