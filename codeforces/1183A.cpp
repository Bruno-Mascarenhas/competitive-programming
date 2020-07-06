#include <iostream>
#include <vector>
#define int long long
using namespace std;

bool check(string s){
    int ans = 0;

    for(int i=0; i<s.size(); i++)
        ans += s[i]-'0';
    
    return ans%4 == 0;
}

signed main(){
    string s;
    cin>>s;

    while(!check(s)){
        int tmp = stoi(s);
        tmp++;
        s = to_string(tmp);
    }

    cout<<s<<endl;
}