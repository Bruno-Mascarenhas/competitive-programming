#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 3.1415926535897932384626
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;

int main(){
    DESYNC;
    int n;
    cin>>n;
    string ans = "", conj = "yY"; 
    if(n == 1)
        puts("Y");
    else if(n == 2)
        puts("yy");
    else if(n == 3)
        puts("yyY");
    else if(n == 4)
        puts("yyyY");
    for(int i=0; i<n; i++){
        if(i%4 == 0) cout<<'y';
        else cout<<'Y';
    }
    cout<<endl;
}