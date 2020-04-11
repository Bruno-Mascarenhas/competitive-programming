#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int v, n;
	cin >> v >> n;
	n*=v;
	for(int i=1; i<=9; ++i){
		if(i>1)
			cout << ' ';
		long double res = ceil(((long double)n/10)*i);
		cout << (int) res;
	}
	cout << endl;
	return 0;
	}
