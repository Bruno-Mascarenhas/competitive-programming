#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cnt = 1;
    cin>>n;
    vector<int> ans;
    while(cnt <= n){
        ans.push_back(cnt);
        n -= cnt;
        cnt += 1;
    }

    ans.back()+=n;

    cout<<ans.size()<<endl;
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}