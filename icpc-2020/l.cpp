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

bool is_anagram(const string& a, const string& b){
    int acount[128] = {};
    int bcount[128] = {};

    for(int i = 0; i < a.size(); ++i)
        acount[a[i]]++;
    for(int i = 0; i < b.size(); ++i)
        bcount[b[i]]++;

    for(int i = 0; i < 128; ++i)    {
        if(acount[i] != bcount[i])
            return false;
    }

    return true;
}

int32_t main() {
	DESYNC;
	cin.exceptions(cin.failbit);

    char mat[41][41];
    int ans[41][41];
    string pvs[21];

    int l, c;
    cin >> l >> c;

    for(int i = 0; i < l; ++i)    {
        for(int j = 0; j < c; ++j)        {
            cin >> mat[i][j];
            ans[i][j] = 0;
        }
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> pvs[i];

    // ROW CHECK
    for(int i = 0; i < l; ++i)    {
        for(int j = 0; j < c; ++j)        {
            for(int k = 0; k < n; ++k)            {
                if(c - j < pvs[k].size())
                    continue;

                string tmp;
                tmp.resize(pvs[k].size());
                for(int u = 0; u < pvs[k].size(); ++u)
                    tmp[u] = mat[i][j + u];

                if(is_anagram(tmp, pvs[k]))                {
                    for(int u = 0; u < pvs[k].size(); ++u)
                        ans[i][j + u] |= (1 << k);
                }
            }
        }
    }

    // COLUM CHECK
    for(int i = 0; i < l; ++i)    {
        for(int j = 0; j < c; ++j)        {
            for(int k = 0; k < n; ++k)            {
                if(l - i < pvs[k].size())
                    continue;

                string tmp;
                tmp.resize(pvs[k].size());
                for(int u = 0; u < pvs[k].size(); ++u)
                    tmp[u] = mat[i + u][j];

                if(is_anagram(tmp, pvs[k]))                {
                    for(int u = 0; u < pvs[k].size(); ++u)
                        ans[i + u][j] |= (1 << k);
                }
            }
        }
    }
    
    // DIAGONAL CHECK
    for(int i = 0; i < l; ++i)    {
        for(int j = 0; j < c; ++j)        {
            for(int k = 0; k < n; ++k)            {
                if(min(l - i, c - j) < pvs[k].size())
                    continue;

                string tmp;
                tmp.resize(pvs[k].size());
                for(int u = 0; u < pvs[k].size(); ++u)
                    tmp[u] = mat[i + u][j + u];

                if(is_anagram(tmp, pvs[k]))                {
                    for(int u = 0; u < pvs[k].size(); ++u)
                        ans[i + u][j + u] |= (1 << k);
                }
            }
        }
    }

    // DIAGONAL CHECK 2
    for(int i = 0; i < l; ++i)    {
        for(int j = 0; j < c; ++j)        {
            for(int k = 0; k < n; ++k)            {
                if(min(l - i, j + 1) < pvs[k].size())
                    continue;

                string tmp;
                tmp.resize(pvs[k].size());
                for(int u = 0; u < pvs[k].size(); ++u)
                    tmp[u] = mat[i + u][j - u];

                if(is_anagram(tmp, pvs[k]))                {
                    for(int u = 0; u < pvs[k].size(); ++u)
                        ans[i + u][j - u] |= (1 << k);
                }
            }
        }
    }

    int ans2 = 0;
    for(int i = 0; i < l; ++i)
        for(int j = 0; j < c; ++j)        {
            if(__builtin_popcount(ans[i][j]) > 1)
                ++ans2;
        }

    cout << ans2 << endl;

}