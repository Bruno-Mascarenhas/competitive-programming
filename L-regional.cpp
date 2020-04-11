#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	bitset<64> bts(n);
//	cout << bts.count() << endl;
//	cout << __builtin_popcount(n) << endl;
	cout << (1ULL << bts.count()) << '\n';
//	cout << (1ULL << __builtin_popcount(n)) << endl;
	return 0;
}
