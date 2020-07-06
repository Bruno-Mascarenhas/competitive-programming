#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, bal=0, ans=0;
        string s;
        cin>>n>>s;

        for(char c: s){
            if(c == '(')
                bal++;
            else{
                bal--;
            }
            if(bal < 0) ans++, bal=0; //change 
        }

        cout<<ans<<endl;
    }
}