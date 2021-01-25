#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, x; cin>>t;
    for(int i=0; i<t; i++){
        cin>>x;
        cout<<(x%2?x:x-1)<<" ";
    }
    cout<<endl;
}