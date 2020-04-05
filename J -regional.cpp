#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define ok cout<<"oi\n";
using namespace std;
typedef pair<int,int> pii;


map<char,int> cards = {{'A',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},
			{'7',7},{'8',8},{'9',9},{'D',10},{'Q',11},{'J',12},{'K',13}};

struct jog{
	set<pair<int,int>> values; // set de freq/carta  , tem que sair primeiro a menor carta
	map<int,int> freq; // set com as atuais freqs e qual cards tem
	int j=0;
	jog(){};
};

int n,k;

int next(int i){
	return ((i+1)%n);
}

int main(){
	cin>>n>>k;

	vector<jog> player(n);
	for(int i=0; i<n; i++){
		if(i == k-1)
			player[i].j = 1;
		for(int j=0; j<4; j++){
			char x; int val;
			cin>>x;
			val = cards[x];

			if(player[i].freq[val]>0){
				pii aux = {player[i].freq[val],val} ;
				player[i].values.erase(aux);
				player[i].freq[val]++;
				player[i].values.insert({player[i].freq[val],val});
			}
			else{
				player[i].freq[val]=1;
				player[i].values.insert({1,val});
			}
		}
	}

//test case = 2 2 A2A2 22AA

	int cur = k-1, joker = 0, flag;

	while(1){

		flag = 0;
		if((--player[cur].values.end())->first == 4)
			return cout<<cur+1<<endl,0;

		if(player[cur].j == 1)
			player[cur].j = 2;

		else if(player[cur].j == 2){
			player[cur].j = 0;
			joker = 1; flag = 1;
			cur = next(cur);
		}
			
		else if(joker == 1){
			player[cur].j = 1;
			joker = 0;
		}

		if(!flag){
			if(player[cur].j == 1)
				player[cur].j = 2;

			int pile = player[cur].values.begin()->second;
			player[cur].values.erase(player[cur].values.begin());
			player[cur].freq[pile]--;

			if(player[cur].freq[pile]>0)
				player[cur].values.insert({player[cur].freq[pile],pile});
	
			cur = next(cur);

			if(player[cur].freq[pile]>0){
				pii aux = {player[cur].freq[pile],pile};
				player[cur].values.erase(aux);
				player[cur].freq[pile]++;
				player[cur].values.insert({player[cur].freq[pile],pile});
			}
			else{
				player[cur].freq[pile]=1;
				player[cur].values.insert({1,pile});
			}
		}
	}	

	return 0;
}
