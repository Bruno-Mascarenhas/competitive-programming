#include <bits/stdc++.h>
using namespace std;

long long int fat;
long long int fatorial(int i){
	fat=1;
	for(int j=1; j<=i; j++){
		fat= fat*j;
	}
	return fat;
}
int main() {
    string s;
	while(cin>>s && s!="0"){
        cout<<fatorial((long long)s.size())<<endl;
	}
	return 0;
}