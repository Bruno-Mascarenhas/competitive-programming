#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    getline(cin,s);
    map<string, int> freq;
    for(int i=0; i<s.size()-1; i++)
        if(s[i]!=' ' && s[i+1]!=' '){
            string aux=""; 
            aux+=tolower(s[i]);
            aux+=tolower(s[i+1]);
            freq[aux]++;
        }
    int big=0; vector<string> ans;
    for(auto it: freq)
        big = max(it.second,big);
    for(auto it: freq)
        if(it.second == big) ans.push_back(it.first);
    sort(ans.begin(),ans.end());
    cout<<ans[0]<<":"<<big<<endl;
}