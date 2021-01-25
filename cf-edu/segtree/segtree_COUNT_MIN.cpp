#include <bits/stdc++.h>
#define int long long
using namespace std;

struct segtree{
    int size;
    vector<pair<int,int>> tree;

    segtree(){};

    segtree(vector<int> arr){
        int sz = 1;

        while(sz < (int) arr.size()) sz*=2;
        size = sz;

        tree.resize(2*size);

        build(arr, 1, 0, size-1);
    }

    void print(){
        for(auto x: tree) cout<<x.first<<" "<<x.second<<" | ";
        cout<<endl;
    }

    pair<int,int> merge(pair<int,int> a, pair<int,int> b){
        if(a.first < b.first) return a;
        else if (b.first < a.first) return b;
        else return {a.first, a.second + b.second};
    }

    void build(vector<int> &arr, int v, int l, int r){
        if(l == r){
            if(l < (int) arr.size())            
                tree[v] = {arr[l],1};
            return;
        }
        int mid = (l+r)/2;
        build(arr, 2*v, l, mid);
        build(arr, 2*v+1, mid+1, r);

        tree[v] = merge(tree[2*v],tree[2*v+1]);
    }

    pair<int,int> query(int v, int l, int r, int lx, int rx){
        if(l > rx || r < lx) return {INT64_MAX,0}; // neutral element
        if(l <= lx && r >= rx) return tree[v];
        int mid = (lx+rx)/2;
        return merge(query(2*v, l, r, lx, mid),query(2*v+1, l, r, mid+1, rx));
    }

    pair<int,int> query(int l, int r) {
        return query(1, l, r, 0, size-1);
    }

    void update(int pos, int val, int v, int l, int r){
        if(l == r){
            tree[v] = {val,1};
        } else {
            int mid = (l+r)/2;
            if(pos <= mid) update(pos, val, 2*v, l, mid);
            else update(pos, val, 2*v+1, mid+1, r);

            tree[v] = merge(tree[2*v],tree[2*v+1]);
        }
    }

    void update(int pos, int val){
        return update(pos, val, 1, 0, size-1);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int n, q, op; 
    cin>>n>>q;
    vector<int> arr(n);
    
    for(int &x: arr) cin>>x;

    segtree st(arr);

    while(q--){
        cin>>op; 
        if(op == 1){
            int pos, val;
            cin>>pos>>val;
            st.update(pos, val);
        } else {
            int l, r;
            cin>>l>>r;
            auto ans = st.query(l, r-1);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
}