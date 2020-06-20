#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    stack<char> super;

    while(1){
        int n = (int)s.size();

        for(int i=0; i<n; i++){
            if(super.empty() || s[i]!=super.top())
                super.push(s[i]);
            else if(!super.empty() && super.top() == s[i])
                super.pop();
        }

        string tmp = "";
        while(!super.empty()){
            tmp+=super.top();
            super.pop();
        }

        s = tmp;

        if((int)s.size() == n) break;
    }

    return s.size() > 0 ? s : "Empty String";
}

int main()
{
    string s;
    getline(cin, s);

    string result = superReducedString(s);

    cout << result << "\n";

    return 0;
}
