#include<vector>
#include<iostream>
using namespace std;

typedef vector<vector<char>> Graf;
typedef vector<vector<bool>> Visitats;
int m;
int n;

void grafs_init(Graf& G, Visitats& V) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> G[i][j];
            if (G[i][j] == 'X') V[i][j] = true;
            else V[i][j] = false; 
        }
    }
}

int DFS(const Graf& G, Visitats& V, int r, int c) {
    int count = 0;
    if (not V[r][c]) {
        V[r][c] = true;
        if (G[r][c] == 't') ++count;
        if (c < m - 1) count += DFS(G, V, r, c + 1);
        if (r < n - 1) count += DFS(G, V, r + 1, c);
        if (c > 0) count += DFS(G, V, r, c - 1);
        if (r > 0) count += DFS(G, V, r - 1, c);
    }
    return count;
}


int main() {
    int r, c;
    cin >> n >> m;  
    Graf G(n, vector<char> (m));  
    Visitats V(n, vector<bool> (m));
    grafs_init(G, V);
    cin >> r >> c;
    --r;
    --c;
    cout << DFS(G, V, r, c) << endl;
}