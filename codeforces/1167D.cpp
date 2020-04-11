#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5*2+10;
int n, id, idc, ans[maxn]; string s; stack<int> cur;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            cur.push(id);
            ans[i] = id%2;
            id++;
        }
        else{
            idc = cur.top(); cur.pop();
            ans[i] = idc%2;
            id--;
        }
    }
    for(int i=0; i<n; i++) cout<<ans[i];
    cout<<endl;
}