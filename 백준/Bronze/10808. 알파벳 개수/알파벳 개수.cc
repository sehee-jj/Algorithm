#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int alph[26];
    fill(alph, alph+26, 0);
    
    for(char c: s) {
        alph[c-97]++;
    }
    for(int cnt: alph) {
        cout<<cnt<<' ';
    }
}