#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
using namespace std;

int32_t main(){
	long long n;
	cin>>n;
	if(n==0) cout<<0<<endl;
	else cout<<((long long)log2(n))+1<<endl;
	return 0;
}
