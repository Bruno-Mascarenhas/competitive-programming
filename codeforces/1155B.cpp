#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; int ans=0,n;
    cin>>n>>s;
    for(int i=0; i<n-10; i++)
        if(s[i] == '8') ans++;
    
    ans > (n-10)/2 ? puts("YES") : puts("NO");

}