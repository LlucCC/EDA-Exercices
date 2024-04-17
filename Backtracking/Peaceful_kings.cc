#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pos;
pos moves[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, - 1}, {-1, 1}, {-1, - 1}};

bool pos_ok(pos p, int n) {
    if (p.first < 0 or p.second < 0) return false;
    else if (p.first >= n or p.second >= n) return false;
    else return true;
}

void print_solution(const vector<vector<bool>>& kings, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            kings[i][j] ? cout << 'K': cout << ".";
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

bool peaceful(pos next, vector<vector<bool>>& Kings) {
    if (next.first != 0 and Kings[next.first - 1][next.second]) return false;
    if (next.second != 0 and Kings[next.first][next.second - 1]) return false;
    if (next.first != 0 and next.second != 0 and Kings[next.first - 1][next.second - 1]) return false;
    if (next.first != 0 and next.second != int(Kings.size()) - 1 and Kings[next.first - 1][next.second + 1]) return false;
    return true;
}

void place_kings_rec(int n, int k, vector<vector<bool>>& Kings, int ki, pos act) {
    if (ki == k) print_solution(Kings, n);
    else if (act.first != n) {
        pos next;
        if (peaceful(act, Kings)) {
            Kings[act.first][act.second] = true;
            next = {act.first, act.second + 2};
            if (next.second >= n) next = {act.first + 1, 0};
            place_kings_rec(n, k, Kings, ki + 1, next);
            Kings[act.first][act.second] = false;
        }
        next = {act.first, act.second + 1};
        if (next.second >= n) next = {act.first + 1, 0};
        place_kings_rec(n, k, Kings, ki, next);
    }
}

void place_kings(int n, int k) {
    vector<vector<bool>> Kings(n, vector<bool>(n, false));
    place_kings_rec(n, k, Kings, 0, {0, 0});
}

int main() {
    int n, k;
    cin >> n >> k;
    place_kings(n, k);
}
