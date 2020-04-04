
#include <bits/stdc++.h> 
using namespace std; 

string p(string s) {
    string r = "";
    int ones = false;
    for(char c : s) {
        if(c == '0') r += (ones ? ")" : "" ), ones = false;
        else {
            if(!ones) r += '(';
            ones = true;
        }

        r += c;
    }
    return (ones) ? r + ')' : r;
}

int main() {
    int T;
    string s;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> s;
        cout << "Case #" << t+1 << ": " << p(s) << endl;
    }
    return 0;
}