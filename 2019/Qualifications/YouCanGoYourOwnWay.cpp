#include <bits/stdc++.h> 
using namespace std; 

int main() {
    int T, N;
    string s;

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'E') s[j] = 'S';
            else s[j] = 'E';
        }
        cout << "Case #" << i+1 << ": " << s << endl;
    }
    return 0;
}
