
#include <bits/stdc++.h> 
using namespace std; 

int M[101][101];


int U(int i, int j, int R, int C) {
    for(int k = i-1; k >= 0; k--)
        if(M[k][j] > 0) return M[k][j];
    return -1;
}
int D(int i, int j,int R, int C) {
    for(int k = i+1; k < R; k++)
        if(M[k][j] > 0) return M[k][j];
    return -1;
}
int L(int i, int j, int R, int C) {
    for(int k = j-1; k >= 0; k--)
        if(M[i][k] > 0) return M[i][k];
    return -1;
}
int Ri(int i, int j, int R, int C) {
    for(int k = j+1; k < C; k++)
        if(M[i][k] > 0) return M[i][k];
    return -1;
}
bool p(int i, int j, int R, int C) {
    int up = U(i,j, R, C), d = D(i,j, R, C), l = L(i,j, R, C), r = Ri(i,j, R, C), n = 0, sum = 0;

    if(up > 0) sum += up, n++;
    if(d > 0)  sum += d, n++;
    if(l > 0)  sum += l, n++;
    if(r > 0)  sum += r, n++;

    double avg = n ? (1.0 * sum) / (1.0 * n) : -1;

    //cout << i << " " << j << " " << M[i][j] << " " << avg << endl;
    return (M[i][j] < avg);

}
long long solve(int R, int C) {
    bool hasElim = true;
    long long inter = 0;
    vector< pair<int, int> > e;
    while(hasElim) {
        hasElim = false;
        for(int i = 0; i < R; i++) 
            for(int j = 0; j < C; j++) 
                if(M[i][j] > 0) {
                    inter += M[i][j];
                    if( p(i, j, R, C) ) {
                        e.push_back( make_pair(i,j) );
                        hasElim = true;
                        //cout << i << " " << j << endl;
                    }
                } 
        for(pair<int, int> E : e) M[E.first][E.second] = -1;
        //cout << inter << endl;           
        
    }
    return inter;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ins, aux;
    long long T, R, C;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> R >> C;

        for(int i = 0; i < R; i++) 
            for(int j = 0; j < C; j++) {
                int aux;
                cin >> aux;
                M[i][j] = aux;
            }
        cout << "Case #" << t+1 << ": " << solve(R, C) << "\n";        
    }
    return 0;
}