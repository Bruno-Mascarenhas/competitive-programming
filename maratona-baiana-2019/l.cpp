#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int x, ans;
int32_t main(){
	for(int i=0; i<7; i++){
		ans = 0;
		for(int j=0; j<7; j++){
			cin>>x;
			if(x) ans++;
		}
		cout<<ans<<endl;
	}
}
