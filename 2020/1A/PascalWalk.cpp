
#include <bits/stdc++.h> 
using namespace std; 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long T, N, sum;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        cout << "Case #" << t+1 << ":\n";

        sum = 0;
        int i = 1;

        if(N < 10) {
            for(i = 1; i <= N; i++) 
                cout << i << " " << i << "\n";
        } else {
            for(i = 1; i <= 2 && sum < N; i++) {
                cout << i << " " << i << "\n";
                sum += 1;
            }
            for(i = 3; i <= N && ((sum + i) < N); i++) {
                cout << i << " " << i-1 << "\n";
                sum += i-1;
            }
            i--;
            for(; sum < N; i++){
                cout << i << " " << i << "\n";
                sum += 1;
            }
        }
    }
    return 0;
}