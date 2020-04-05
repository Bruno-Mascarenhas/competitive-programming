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

struct node{
    node *l, *r;
    int h, val;
    node(){h=0;val=0;l=NULL;r=NULL;};
    node(int v, int alt) : val(v), l(NULL), r(NULL), h(alt) {};
};

void insert(int val, node *no){
    node *curr = no; int alt = curr->h;
    while(curr!=NULL){
        alt = curr->h;
        if(val <= curr->val)
            if(curr->l == NULL){
                curr->l = new node(val,alt+1);
                curr = curr->l;
                break;
            }
            else 
                curr = curr->l;
        else 
            if(curr->r == NULL){
                curr->r = new node(val,alt+1);
                curr = curr->r;
                break;
            }
            else
                curr = curr->r;
    }
    cout<<curr->h<<endl;
}



int main(){
    DESYNC;
    int n;
    cin>>n;
    int a;
    cin>>a;
    node *tree = new node(a,1);
    cout<<1<<endl;
    for(int i=1; i<n; i++){
        int x; cin>>x;
        insert(x,tree);
    }
}