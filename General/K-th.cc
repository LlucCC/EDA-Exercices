#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int k_esim(int k, const VVI& V) {
    priority_queue<pair <int, pair<int, int>>> PQ;
    int n = V.size();
    for (int i = 0; i < n; ++i) {
        if(V[i].size() > 0) PQ.push(make_pair(-V[i][0], make_pair(i, 0)));
    }
    pair<int, pair<int, int>> temp = PQ.top();
    for (int i = 0; i < k; ++i) {
        if (not PQ.empty()) {
            temp = PQ.top(); 
            PQ.pop();
            if (temp.second.second + 1 < V[temp.second.first].size()) PQ.push(make_pair(-V[temp.second.first][temp.second.second + 1], make_pair(temp.second.first, temp.second.second + 1)));
        }
    }
    return -temp.first;
}