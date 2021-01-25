#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; string s;
    cin>>n>>k>>s;

    map<char, int> freq;
    for(char x: s) freq[x]++;

    for(int i=0; i<k; i++)
        for(char x = 'a'; x <= 'z'; x++)
            if(freq[x]>0){
                freq[x]--;
                break;
            }
    
    string ans = "";
    for(int i=n-1; i>=0; i--)
        if(freq[s[i]] > 0){
            ans+=s[i];
            freq[s[i]]--;
        }

    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}