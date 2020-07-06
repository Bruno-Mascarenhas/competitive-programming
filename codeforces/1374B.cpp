#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;

    while(t--){
        int n, div2 = 0, div3 = 0;
        cin>>n;

        while(n%2 == 0){
            div2++;
            n/=2;
        }

        while(n%3 == 0){
            div3++;
            n/=3;
        }

        if(n == 1 && div2 <= div3){
            cout<<div3*2 - div2<<endl;
        }  else {
            cout<<-1<<endl;
        }
    }
}