#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; string s;
        cin>>n>>s;

        bool ok = false;
        int posf = s.find("2020"), posb = s.rfind("2020");
        ok |= ((posf!=string::npos && (posf==0 || posf==n-4)) || (posb!=string::npos && (posb==0 || posb==n-4)));
        posf = s.find("2"), posb = s.rfind("020");
        ok |= (posf==0 && posb==n-3);
        posf = s.find("20"), posb = s.rfind("20");
        ok |= (posf==0 && posb==n-2);
        posf = s.find("202"), posb = s.rfind("0");
        ok |= (posf==0 && posb==n-1);

        cout<<(ok?"YES\n":"NO\n");
    }
}