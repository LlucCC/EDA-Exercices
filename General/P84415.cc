#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string, int> bag;
    string op;
    while (cin >> op) {
        if (op == "minimum?"){
            if (bag.empty()) cout << "indefinite minimum" << endl;
            else cout << "minimum: " << bag.begin() -> first << ", " << bag.begin() -> second << " time(s)" << endl;
        }
        else if (op == "store") {
            string w;
            cin >> w;
            if (not (bag.insert(make_pair(w, 1)).second)) ++bag[w]; 
        }
        else if (op == "delete"){
            string w;
            cin >> w;
            map<string, int>::iterator it = bag.find(w);
            if (it != bag.end()) --(it -> second);
            if (it -> second == 0) bag.erase(it);
        }
        else {
            if (bag.empty()) cout << "indefinite maximum" << endl;
            else {
                map<string, int>::iterator max = bag.end();
                --max;
                cout << "maximum: " << max -> first << ", " << max -> second << " time(s)" << endl;
            }
        }  
    }
}