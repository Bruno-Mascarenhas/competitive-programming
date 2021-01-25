#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//Compilation flags // g++ -std=c++17 -O3 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g 
using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define pi 3.1415926535897932384626
#define pb push_back
#define EPS 1e-9
#define INF 1e18
#define m1(x) memset((x), -1, sizeof(x))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
const int MOD = 1e9+7;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

ll mod(ll x){
	x %= MOD;
	return x < 0 ? x += MOD : x;
}

int32_t main() {
	DESYNC;
	cin.exceptions(cin.failbit);

    string s;
    cin >> s;

    int l = 0, r = 0;
    int gl = 0, gr = 0;
    int sacando = 0;

    for(int i = 0; i < s.size(); ++i)    {
        if(s[i] == 'Q')        {
            if(gl >= 2 || gr >= 2)            {
                cout << gl;
                if(gl >= 2) cout << " (winner)";
                cout << " - ";
                cout << gr;
                if(gr >= 2) cout << " (winner)";
                cout << endl;
            }
            else            {
                cout << gl << " (" << l;
                if(sacando == 0) cout << '*';
                cout << ')';
                cout << " - ";
                cout << gr << " (" << r;
                if(sacando == 1) cout << '*';
                cout << ')';
                cout << endl;
            }
        }
        else if(s[i] == 'R')        {
            if(sacando == 0) { ++r; sacando = 1; }
            else { ++l; sacando = 0; }
        }
        else if(s[i] == 'S')        {
            if(sacando == 0) { ++l; sacando = 0; }
            else { ++r; sacando = 1; }
        }

        if(l >= 10 || (l >= 5 && l-r >= 2))        {
            ++gl;
            sacando = 0;
            l = 0, r = 0;
        }
        else if(r >= 10 || (r >= 5 && r-l >= 2))        {
            ++gr;
            sacando = 1;
            l = 0, r = 0;
        }
    }

}