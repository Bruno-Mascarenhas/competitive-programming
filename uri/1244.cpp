#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

bool compare(string a, string b){
	return a.size() > b.size();
}

int main() {
	int n;
	scanf("%d", &n);
	cin.ignore();
	while(n--) {
		string s, temp;
		getline(cin, s);
		vector<string> part;
		stringstream a;
		a << s;
		while(a>>temp) {
			part.push_back(temp);
		}
		stable_sort(part.begin(),part.end(),compare);
		int cont = part.size();
		for (int z=0; z<cont; z++) cout << part[z] << ((z!=cont-1)?" ":"\n");
	}
	return 0;
}
