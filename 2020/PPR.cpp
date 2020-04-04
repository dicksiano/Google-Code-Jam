
#include <bits/stdc++.h> 
using namespace std; 

int T, N;
vector<vector<int> > A(1001, vector<int>(2, 0) ), memo;

int main() {
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        map< vector<int>, int> m, f;

        for(int i = 0; i < N; i++) cin >> A[i][0] >> A[i][1];
        for(int i = 0; i < N; i++) {
            f[ {A[i][0], A[i][1]} ]++;
            m[ {A[i][0], A[i][1], f[ {A[i][0], A[i][1]} ]}  ] = i;
        }
        
        f = {};
        sort(A.begin(), A.begin() + N);

        string s(N, 'z');
        int a = -1, b = -1;
        for(int i = 0; i < N && (s[0] != 'I'); i++) {
            f[ {A[i][0], A[i][1]} ]++;
            if(a <= A[i][0])      a = A[i][1], s[ m[ {A[i][0], A[i][1], f[ {A[i][0], A[i][1]} ]} ] ] = 'C';
            else if(b <= A[i][0]) b = A[i][1], s[ m[ {A[i][0], A[i][1], f[ {A[i][0], A[i][1]} ]} ] ] = 'J';
            else s = "IMPOSSIBLE";
        }
        cout << "Case #" << t+1 << ": " << s << endl;
    }
    return 0;
}