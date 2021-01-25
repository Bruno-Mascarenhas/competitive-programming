#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; int n;
    cin>>n>>s;

    for(int i=1; i<=n; i++){
        if(n%i == 0){
            reverse(s.begin(),s.begin()+i);
        }
    }

    cout<<s<<endl;
}