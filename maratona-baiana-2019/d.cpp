#include <bits/stdc++.h>
#define endl '\n'
#define res(x) cout << x << endl
using namespace std;

int a, b, c;
int32_t main(){
	cin >> a >> b >> c;
	if(a>30)
		if(b>30||c>30)
			res("invalida");
		else if (b>12)
			if(c>12)
				res("invalida");
			else
				res("a-d-m");
		else if (c>12)
			res("a-m-d");
		else
			res("ambigua");
	else if(b>30)
		if(c>30)
			res("invalida");
		else if (a>12)
			if(c>12)
				res("invalida");
			else
				res("d-a-m");
		else if (c>12)
			res("m-a-d");
		else
			res("ambigua");
	else if (c>30)
		if (a>12)
			if(b>12)
				res("invalida");
			else
				res("d-m-a");
		else if (b>12)
			res("m-d-a");
		else
			res("ambigua");
	else
		res("ambigua");
	return 0;

}