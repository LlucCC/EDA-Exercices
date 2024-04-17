#include<iostream>
#include<vector>
using namespace std;
pair<int, int> moves[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pair<int, int> Ghost[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, - 1}, {-1, 1}, {-1, - 1}};

//Funció per veure si la posició es surt del mapa
inline bool pos_ok(int x, int y, int n, int m) {
    if (x < 0 or y < 0) return false;
    if (x >= n or y >= m) return false;
    return true;
}

//Retorna cert si el pac-man pot arribar a algun pellet
bool pac_man(vector<vector<char>>& Board, vector<vector<bool>>& Invalid, int x, int y) {
    if (Board[x][y] == 'B') return true;
    else {
        for (int i = 0; i < 4; ++i) {
            int nextX = x + moves[i].first;
            int nextY = y + moves[i].second;
            if (pos_ok(nextX, nextY, Board.size(), Board[0].size()) and not Invalid[nextX][nextY]) {
                Invalid[nextX][nextY] = true;
                if (pac_man(Board, Invalid, nextX, nextY)) return true;
            } 
        }
    }
    return false;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int x, y;
        vector<vector<char>> Board(n, vector<char> (m));
        vector<vector<bool>> Invalid(n, vector<bool> (m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> Board[i][j];
                if (Board[i][j] == 'X') Invalid[i][j] = true;
                else if (Board[i][j] == 'F') {
                    Invalid[i][j] = true;
                    for (int k = 0; k < 8; ++k) {
                        int auxi = i + Ghost[k].first;
                        int auxj = j + Ghost[k].second;
                        if (pos_ok(auxi, auxj, n, m)) Invalid[auxi][auxj] = true;
                    }
                }
                else if (Board[i][j] == 'P') {
                    x = i;
                    y = j;
                }
            } 
        }
        if (Invalid[x][y]) cout << "no" << endl;
        else if (pac_man(Board, Invalid, x, y)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}