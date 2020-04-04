
#include <bits/stdc++.h> 
using namespace std; 

string p(string s, int i, int t, string &sol) {
    if(i >= s.size()) {
        while(t--) sol += ")";
        return sol;
    }

    int x = s[i] - '0';

    for(; t > x; t--) sol += ")";
    for(; t < x; t++) sol += "(";
    sol.push_back(s[i]);

    return p(s, i+1, t, sol);
}

int main() {
    int T;
    string s, sol;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> s;
        sol = "";
        cout << "Case #" << t+1 << ": " << p(s, 0, 0, sol) << endl;
    }
    return 0;
}