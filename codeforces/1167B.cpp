#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int main(){
    int arr[] = {4,8,15,16,23,42}, ans[6], n, n2;
    set<int> nums (arr,arr+6);
    cout<<"? 1 1"<<endl;
    cin>>n;
    n = sqrt(n);
    ans[0] = n; nums.erase(n);
    cout<<"? 2 2"<<endl;
    cin>>n;
    n = sqrt(n);
    ans[1] = n; nums.erase(n);
    cout<<"? 3 4"<<endl;
    cin>>n;
    cout<<"? 3 5"<<endl;
    cin>>n2;

    pair<int,int> pos1, pos2;

    for(int i=0; i<6; i++)
        for(int j = i+1; j<6; j++)
            if(arr[i] * arr[j] == n)
               pos1 = {i,j};

    for(int i=0; i<6; i++)
        for(int j = i+1; j<6; j++)
            if(arr[i] * arr[j] == n2)
               pos2 = {i,j};

    if(pos1.ff == pos2.ff)
        ans[2] = arr[pos1.ff];
    else if(pos1.ff == pos2.ss)
        ans[2] = arr[pos1.ff];
    else if(pos1.ss == pos2.ff)
        ans[2] = arr[pos1.ss];
    else 
        ans[2] = arr[pos1.ss];

    nums.erase(ans[2]);
    ans[3] = n / ans[2];
    ans[4] = n2 / ans[2];
    nums.erase(ans[3]); nums.erase(ans[4]);
    ans[5] = *nums.begin();

    cout<<"! ";
    for(int i=0; i<6; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    string s;
    cin>>s;
    return 0;
}
    