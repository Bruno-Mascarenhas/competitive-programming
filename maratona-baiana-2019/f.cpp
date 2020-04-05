#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
using namespace std;

int l,c, ano, mes, dia;
char ans[110][110], in[110][110];
int32_t main(){
	cin>>l>>c;
	vector<pair<int,int>> resp;
	for(int i=0; i<l; i++)
		for(int j=0; j<c; j++)
				cin>>in[i][j];
			
	for(int i=0; i<l; i++)
		for(int j=0; j<c; j++){
				cin>>ans[i][j];
				if(ans[i][j] != in[i][j])
					resp.pb({i,j});
			}
	for(auto it: resp)
		cout<<it.ff+1<<" "<<it.ss+1<<endl;
}
