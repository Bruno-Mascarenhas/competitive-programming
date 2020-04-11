#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef struct time{
	int gol,vit,pt;
	string name;
	bool operator <(time &other) const {
		if(pt > other.pt)
			return true;
		else if(pt < other.pt)
			return false;
		else if(vit > other.vit)
			return true;
		else if(vit < other.vit)
			return false;
		else if(gol > other.gol)
			return true;
		else if(gol < other.gol)
			return false;
		else
			return name < other.name;
	}
} ttime;

int main(){
	vector<ttime> times(4);
	map<string,int> mapa;
	string a, b;
	int n, x, y;

	for(int i=0; i<4; i++){
		cin >> times[i].name;
		times[i].gol = 0;		
		times[i].vit = 0;		
		times[i].pt = 0;		
		mapa[times[i].name] = i;
	}
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a >> x >> b >> y;
		times[mapa[a]].gol += x-y;
		times[mapa[b]].gol += y-x;
		if(x > y){
			times[mapa[a]].pt += 3;
			times[mapa[a]].vit += 1;
		} else if(y > x) {
			times[mapa[b]].pt += 3;
			times[mapa[b]].vit += 1;
		} else {
			times[mapa[a]].pt += 1;
			times[mapa[b]].pt += 1;
		}
	}
	sort(times.begin(), times.end());
	cout << times[0].name << endl;
	cout << times[1].name << endl;
}
