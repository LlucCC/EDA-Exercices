#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<pair<int, int>>> Graph;

bool Dijkstra(const Graph& G, int x, int y, vector<int>& p) {
    int n = G.size();
    vector<int> D(n, 2147483647);
    D[x] = 0;
    vector<bool> V(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push(make_pair(0, x));
    while (not PQ.empty()) {
        int act = PQ.top().second; 
        PQ.pop();
        if (not V[act]) {
            if (act == y) {
                return true;
            }
            V[act] = true;
            for (int i = 0; i < G[act].size(); ++i) {
                int next = G[act][i].first;
                int c = G[act][i].second;
                if (D[next] > D[act] + c) {
                    D[next] = D[act] + c;
                    p[next] = act;
                    PQ.push(make_pair(D[next], next));
                }
            }
        }
    }
    return false;
}

void write_path(vector<int>& p, int y, int x) {
    if (y == x) cout << y;
    else {
        write_path(p, p[y], x);
        cout << " " << y;
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        int u, v, c;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            G[u].push_back(make_pair(v, c)); 
        }
        
        int x, y;
        cin >> x >> y;
        vector<int> p(n, -1);
        bool found = Dijkstra(G, x, y, p);
        if (not found) cout << "no path from " << x << " to " << y;
        else write_path(p, y, x);
        cout << endl;
    }
}