#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, c, x;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        cin>>m>>c;
        vector<int> arr[m];
        for(int i=0; i<c; i++){
            cin>>x;
            arr[x%m].push_back(x);
        }
        for(int i=0; i<m; i++){
            cout<<i<<" -> ";
            for(int x: arr[i])
                cout<<x<<" -> ";
            cout<<"\\\n";
        }
        if(n>0)cout<<endl;
    }
}