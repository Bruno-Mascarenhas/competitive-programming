#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
	int a;
	while(scanf("%d",&a)!=EOF) {
		vector<int> s;
		while(a--){	
			int b;
			cin>>b;
			s.push_back(b);
		}		
		sort(s.begin(),s.end());
		int tam=s.size();
		for (int i=0; i<tam; i++) printf("%04d\n", s[i]);
	}
	return 0;
}