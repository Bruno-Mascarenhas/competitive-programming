#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int n, ans=0, cnt=0;
char mat[110][110];

int main(){
    cin>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];

    for(int i=0; i<n; i++){
        if(i%2){
            for(int j=n-1; j>=0; j--){
                if(mat[i][j] == 'o') cnt++;
                else if(mat[i][j] == 'A') ans=max(ans,cnt),cnt=0;
            }
        }
        else{
            for(int j=0; j<n; j++){
                if(mat[i][j] == 'o') cnt++;
                else if(mat[i][j] == 'A') ans=max(ans,cnt),cnt=0;
            }
        }
    }

    cout<<max(cnt,ans)<<endl;
    
}