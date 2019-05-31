#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string,string> a, pair<string,string> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<pair<string,string>> arr;    
    string s; pair<string, string> sup;
    while(getline(cin,s)){
        sup.second = s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        sup.first = s;
        arr.push_back(sup);
    }
    sort(arr.rbegin(),arr.rend());
    cout<<arr[0].second<<endl;
}