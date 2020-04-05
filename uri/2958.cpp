#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> v, d;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            string s;
            cin>>s;
            s[s.size()-1] == 'V' ? v.push_back(s) : d.push_back(s);
        }

    sort(v.rbegin(), v.rend());
    sort(d.rbegin(),d.rend());

    for(auto x: v) cout<<x<<endl;
    for(auto x: d) cout<<x<<endl;
}