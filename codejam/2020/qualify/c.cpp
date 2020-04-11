#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct task{
  int id, st, end;
  task(int i, int s, int e): id(i), st(s), end(e) {};
  task(){};
};

vector<task> tasks;
int p[2], T, n, ini, fim;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>T;

  for(int t=1; t<=T; t++){
    bool valid = 1;
    p[0] = p[1] = 0;
    cin>>n;

    string ans(n,'x');

    for(int i=0;i<n; i++){
      cin>>ini>>fim;
      tasks.pb({i,ini,fim});
    }

    sort(tasks.begin(),tasks.end(),
          [&](task a, task b){
            return a.st < b.st | (a.st == b.st && a.end > b.end);
          });

    for(int i=0; i<n; i++){
      if(p[0] <= tasks[i].st){
        ans[tasks[i].id] = 'C';
        p[0] = tasks[i].end;
      }
      else if(p[1] <= tasks[i].st){
        ans[tasks[i].id] = 'J';
        p[1] = tasks[i].end;
      }
      else {
        valid = 0;
        break;
      }
    }
    cout<<"Case #"<<t<<": "<<(valid?ans:"IMPOSSIBLE")<<"\n";

    tasks.clear();
  }
}
