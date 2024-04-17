#include<queue>
#include<vector>
#include<iostream>
using namespace std;

typedef vector<vector<pair<int, int>>> Graph;

int MST(Graph& G) { 
    int n = G.size();
    vector<bool> V(n, false);
    V[0] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    for (pair<int, int> x: G[0]) PQ.push(x);
    int vis = 1;
    int sum = 0;
    while (vis < n) {
        int c = PQ.top().first; 
        int act = PQ.top().second;
        PQ.pop();
        if (not V[act]) {
            V[act] = true;
            for (pair<int, int> x: G[act]) PQ.push(x);
            sum += c;
            ++vis;
        }
    }
    return sum;
}


int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            G[u - 1].push_back(make_pair(c, v - 1));
            G[v - 1].push_back(make_pair(c, u - 1));
        }
        
        int mst = MST(G);
        cout << mst << endl;
    }
}