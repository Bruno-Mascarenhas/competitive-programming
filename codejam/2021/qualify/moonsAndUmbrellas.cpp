#include <bits/stdc++.h>
using namespace std;

void testcase(){
    int x, y, n;
    cin>>x>>y;

    string s;
    cin>>s;
    n = s.size();

    const int INF = 1e9+5; 
    int last_c = 0, last_j = 0;

    for(int i=0; i<n; i++){
        int new_c = INF, new_j = INF;
        if(s[i] == '?' || s[i] == 'C')
            new_c = min(last_c, last_j + y);
        if(s[i] == '?' || s[i] == 'J')
            new_j = min(last_j, last_c + x);
        
        last_c = new_c;
        last_j = new_j;
    }

    cout<<min(last_c, last_j)<<endl;
}

int main(){
    int t; cin>>t;
    for(int cx=1; cx<=t; cx++){
        cout<<"Case #"<<cx<<": ";
        testcase();
    }
} 