#include <bits/stdc++.h>
using namespace std;
typedef long long int llong;

int main() {
	llong n,q,t;
	cin >> t >> n >> q;
	while (t-- != 0)   {
		vector <llong> mnd;
		cout << "1 2 3" << endl;
		llong cLength = 3;
		llong midP;
		cin >> midP;
		if(midP==3)    {
			mnd.push_back(1);
			mnd.push_back(3);
			mnd.push_back(2);
		}
		else if(midP==2)    {
			mnd.push_back(1);
			mnd.push_back(2);
			mnd.push_back(3);
		}
		else    {
			mnd.push_back(2);
			mnd.push_back(1);
			mnd.push_back(3);
		}
		llong i = 4;
		while(i<=(n)) {      
			llong v = cLength - 1;
			llong u = 0;
			while (u < v) {
				llong mid = u + ((v - u) / 2);
				cout << mnd[mid] << " " << mnd[mid + 1] << " " << (i) << endl;
				cin >> midP;
				if(midP == mnd[mid + 1])        {
					u = mid + 1;
				}
				else if (midP == mnd[mid])        {
					v = mid;
				}
				else        {
					mnd.insert(mnd.begin() + mid + 1, i);
					cLength++;
					break;
				}
			}
			if (i != cLength) {
				if (u == 0) {
					mnd.insert(mnd.begin(), i);
				} else {
					mnd.push_back(i);
				}
				cLength++;
			}
			i++;
		}
		for (auto itt: mnd) {
			cout << itt << " ";
		}
		cout << endl;
		cin >> midP;
		if (midP == -1) {
			break;
		}
	}
}