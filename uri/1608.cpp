#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int out = 1e9;
int t, d, in, b, arr[111], ans, aux, x, y, q;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans = out;		
		cin>>d>>in>>b;
		for(int i=0; i<in; i++)
			cin>>arr[i];
		for(int i=0; i<b; i++){
			cin>>q; aux = 0;
			for(int i=0; i<q; i++){
				cin>>x>>y;
				aux+=arr[x]*y;
			}
			ans = min(ans,aux);
		}
		cout<<d/ans<<endl;
	}

}