
#include <bits/stdc++.h> 
using namespace std; 


int main() {
    int T, N;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        cout << "Case #" << t+1 << ": " << endl;

        for(int i = 1; i <= N; i++) cout << i << " " << i << " " << endl;
    }
    return 0;
}