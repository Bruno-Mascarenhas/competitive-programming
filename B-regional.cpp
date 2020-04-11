#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int carlos;
	cin >> carlos;
	int x;
	for(int i = 0; i < n-1; ++i){
		cin >> x;
		if(x > carlos){
			cout << "N\n";
			return 0;
		}
	}
	cout << "S\n";



}
