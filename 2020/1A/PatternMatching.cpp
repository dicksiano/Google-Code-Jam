
#include <bits/stdc++.h> 
using namespace std; 

vector<vector<string>> v;
vector<string> auxV;

string solve(vector<string> &A) {
    string sol = "";
    for(string s : A) {
        bool flag = true;
        for(string p : A) {
            size_t found = s.find(p); 
            flag &= (found != string::npos);
        }

        if(flag && (s.size() > sol.size()) ) sol = s;
    }

    return (sol.size() == 0) ? "*" : sol;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ins, aux;
    long long T, N;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        v.clear();
        auxV.clear();

        for(int i = 0; i < N; i++) {
            cin >> ins;
            auxV.push_back(&ins[1]);
        }
        cout << "Case #" << t+1 << ": " << solve(auxV) << "\n";        
    }
    return 0;
}