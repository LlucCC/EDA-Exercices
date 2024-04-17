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

bool DFS(const Graf& G, Visitats& V, int r, int c) {
    if (not V[r][c]) {
        V[r][c] = true;
        if (G[r][c] == 't') return true;
        else if (c < m - 1 and  DFS(G, V, r, c + 1)) return true;
        else if (r < n - 1 and  DFS(G, V, r + 1, c)) return true;
        else if (c > 0 and  DFS(G, V, r, c - 1)) return true;
        else if (r > 0) return DFS(G, V, r - 1, c);
        else return false;
    }
    else return false;
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
    if (DFS(G, V, r, c)) cout << "yes" << endl;
    else cout << "no" << endl;
}