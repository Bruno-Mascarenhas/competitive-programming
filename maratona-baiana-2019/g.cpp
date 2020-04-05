#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
using namespace std;

int n, q4, q5, q6, x, y, ans; set<int> nums;
int32_t main(){
	for(int i=0; i<6; i++){
		cin>>x;
		nums.insert(x);
	}
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x; ans=0;
		for(int j=0; j<x; j++){
			cin>>y;
			if(nums.count(y))
				ans++;
		}
		if(ans ==4) q4++;
		if(ans ==5) q5++;
		if(ans ==6) q6++;
	}
	cout<<q6<<" "<<q5<<" "<<q4<<" "<<endl;	
}
