#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

using ii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vii = vector<ii>;

#define ff first
#define ss second
#define pb push_back

#define EPS 1e-9
#define INF (int32_t(1e9)+1)
#define MAX (int32_t(1e6)+1)
#define M (int32_t(1e9)+7)

#define endl "\n"
#define debug(x) (cerr << #x << " = " << (x) << endl)
#define desync() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

inline int mod(int n, int m){
    int ret = n%m; 
    if(ret < 0) ret += m;
    return ret;
}

/**
 * Extended Euclidian GCD.
 *
 * Time Complexity: O(log(min(a, b))).
 */
pair<int, ii> gcd(int a, int b){
    if(a == 0) return {b, {0, 1}};
    pair<int, ii> res = gcd(b%a, a);
    int x1 = res.ss.ff, y1 = res.ss.ss;
    return {res.ff, {y1 - b/a*x1, x1}};
}

/**
 * Euclidian derivated LCM.
 *
 * Time Complexity: O(log(min(a, b))).
 */
int lcm(int a, int b){
    // same as a*b/gcd(a, b) but avoiding overflow.
    return a/gcd(a, b).ff*b;
}

int32_t main(){
    desync();
    int n, a, b, aux = 0;
    cin >> n >> a >> b;
    if(n < a){
        cout << "NO" << endl;
        return 0;
    }

    vector<int> ans;
    while(aux < n and ans.size() < int32_t(1e5)){
        ans.pb(b);
        aux += b;
    }
    int diff = aux - n;
    for(int i=0; i<ans.size() and diff > 0; ++i){
        ans[i] = max(a, ans[i] - diff);
        diff -= (b-ans[i]);
    }
    if(diff == 0){
        cout << "YES" << endl;
        for(int i=0; i<ans.size(); ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
