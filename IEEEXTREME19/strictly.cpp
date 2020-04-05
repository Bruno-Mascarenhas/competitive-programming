#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 3.1415926535897932384626
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;

//Compilation flags // g++ -std=c++17 -O3 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g 
struct point{
    int x, y;
    point(){};
    point(int _x, int _y) : x(_x), y(_y) {};
 
    bool operator<(const point &a) const{
        return make_pair(x,y) < make_pair(a.x,a.y);
    }

    point operator+(const point &a){
        return point(x + a.x, y + a.y);
    }
 
    point operator-(const point &a){
        return point(x - a.x, y - a.y);
    }
};
 
int dot(point a, point b){
    return a.x*b.x + a.y*b.y;
}
 
int cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}

bool ccw(point a, point b, point c){
    return cross(b-a,c-a) > 0;
}
 
bool intersect(point a, point b, point c, point d){
    if(ccw(a,b,c) != ccw(a,b,d) && ccw(c,d,a) != ccw(c,d,b))
        return true;
    return false;
}

vector<point> ConvexHull(vector<point> points){
    int n = points.size(), k = 0;
 
    sort(points.begin(),points.end());
 
    vector<point> ans(2*n);
 
    for(int i=0; i<n; i++){
        while(k>=2 && !ccw(ans[k-2],ans[k-1],points[i])) k--;
        ans[k++] = points[i];
    }
 
    for(int i=n-2, t=k+1; i>=0; i--){
        while(k>=t && !ccw(ans[k-2],ans[k-1],points[i])) k--;
        ans[k++] = points[i];
    }
 
    ans.resize(k);
    return ans;
}

bool onSegment(point a, point b, point c){ 
    int crossproduct = (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);
    if(crossproduct != 0) return false;
    int dotproduct = (c.x - a.x) * (b.x - a.x) + (c.y - a.y)*(b.y - a.y);
    if(dotproduct < 0)  return false;
    int squaredlengthba = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    if(dotproduct > squaredlengthba) return false;

    return true;
} 

int n, m;
int32_t main(){
    DESYNC;
    cin>>n>>m;
    vector<point> hull(n), pts(m);
    for(auto &x:hull) cin>>x.x>>x.y;
    for(auto &x:pts) cin>>x.x>>x.y;
    vector<point> polygon = ConvexHull(hull);
    int ans=0;
    map<pair<point,point>,int> cnt;

    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            if(i!=j){
                bool f = 1;
                for(int k=1; k<n; k++)
                    if(intersect(pts[i],pts[j],polygon[k],polygon[k-1]) || onSegment(pts[i],pts[j],polygon[k]) || onSegment(pts[i],pts[j],polygon[k-1])){
                        f=0; break;
                    }
                if(f){ 
                    if(cnt[{pts[i],pts[j]}]==0 && cnt[{pts[j],pts[i]}]==0){
                        ans++;
                        cnt[{pts[i],pts[j]}]=1;
                        //cout<<pts[i].x<<" "<<pts[i].y<<" "<<pts[j].x<<" "<<pts[j].y<<endl;
                    }
                }
            }

    cout<<ans<<endl;
}
    