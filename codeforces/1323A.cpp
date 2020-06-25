#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;

    while(t--){
        int n, x;
        vector<int> odd, even;
        cin>>n;

        for(int i=1; i<=n; i++){
            cin>>x;
            x%2 ? odd.push_back(i) : even.push_back(i);
        }
        if(odd.size() >= 2){
            cout<<2<<endl;
            for(int i=0; i<2; i++) cout<<odd[i]<<" ";
            cout<<endl;
        } else if(even.size() > 0){
            cout<<1<<endl<<even[0]<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
}