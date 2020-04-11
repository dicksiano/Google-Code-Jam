
#include <bits/stdc++.h> 
using namespace std; 

void p(vector<vector<int> > &m, int &k, int &r, int &c, int N) {
    for(int i = 0; i < N; i++) k += m[i][i];

    unordered_set<int> h;
    for(int i = 0; i < N; i++) {
        h.clear();

        for(int j = 0; j < N; j++) {
            if( h.find(m[i][j]) != h.end() ) r++, j = N;
            else h.insert(m[i][j]);
        }
    }
    for(int i = 0; i < N; i++) {
        h.clear();

        for(int j = 0; j < N; j++) {
            if( h.find(m[j][i]) != h.end() ) c++, j = N;
            else h.insert(m[j][i]);
        }
    }
}

int main() {
    int T, N;
    vector<vector<int> > m;
    vector<int> aux;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;

        m.clear();

        for(int i = 0; i < N; i++) {
            aux.clear();
            int x;
            for(int j = 0; j < N; j++) {
                cin >> x;
                aux.push_back(x);
            }

            m.push_back(aux);
        }

        int k = 0, r = 0, c = 0;
        p(m, k, r, c, N);
        cout << "Case #" << t+1 << ": " << k << " " << r << " " << c << endl;
    }
    return 0;
}