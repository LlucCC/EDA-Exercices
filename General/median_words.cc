#include<vector>
#include<iostream>
#include<set>
using namespace std;


int main(){
    set<string> S;
    string s;
    set<string>::iterator mid;
    cin >> s;
    if (s != "END") {
        S.insert(s);
        mid = S.begin();
        cout << s << endl;
        cin >> s;
    }   
    while (s != "END") {
        S.insert(s);
        if (s < *mid and S.size()%2 == 0) --mid;
        else if (s > *mid and S.size()%2 == 1) ++mid;
        cout << *mid << endl;
        cin >> s;
    }   
    //int size = VS.size();
    //for (int i = 0; i < size; ++i) cout << VS[i] << endl;
}