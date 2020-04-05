#include <bits/stdc++.h>
#define int long long
using namespace std;

struct point{
    int x, y, big;
    point() {};
    point(int _x, int _y): x(_x), y(_y), big(max(_x,_y)) {};

    bool operator<(const point &oth){
        if(big < oth.big) return true;
        else if(big == oth.big && x < oth.x) return true;
        else if(big == oth.big && y > oth.y) return true;
        return false;
    }
};

int dist(point a, point b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<int,vector<point>> levels;
    
    int n,a,b;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        levels[max(a,b)].push_back(point(a,b));
    }

    vector<pair<point,point>> dp(levels.size());
    last = 0;
    point pti = {0,0};
    dp[0] = point(0,0);
    dp[1] = point(0,0);
    
    for(auto it: levels){
        if(it.first == 0) continue;
        int cur  = it.first;
        sort(it.second.begin(),it.second.end());
        

        last = cur;
    }


}