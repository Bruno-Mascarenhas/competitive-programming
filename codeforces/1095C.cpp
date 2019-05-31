#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, cur;
map<int,int> ans; queue<int> nums;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0; i<=30; i++)
        if(n & (1<<i)){
            ans[1<<i]++; cnt++;
            if(i)
                nums.push(1<<i);
        }
    if(ans.size() > k || k > n)
        return puts("NO"), 0;

    while(cnt < k && !nums.empty()){
        cur = nums.front(); nums.pop();
        if(cur/2 > 1){
            nums.push(cur/2); nums.push(cur/2);
        }
        cnt++;
        ans[cur]--;
        ans[cur/2]+=2;
    }
    if(cnt < k) return puts("NO"), 0;
    cout<<"YES\n";
    for(auto it = ans.begin(); it!=ans.end(); it++)
        for(int i=0; i<it->second; i++)
            cout<<it->first<<" ";
    cout<<endl;
}