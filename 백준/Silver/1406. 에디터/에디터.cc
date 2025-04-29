#include <iostream>
#include <list>
using namespace std;

list<char> str;
list<char>::iterator cursor;

void instr_L() {
    if (cursor == str.begin())
        return;
    cursor--;
    return;
}

void instr_D() {
    if (cursor == str.end())
        return;
    cursor++;
    return;
}

void instr_B() {
    if (cursor == str.begin())
        return;
    cursor=str.erase(--cursor);
    return;
}

void instr_P(char c) {
    str.insert(cursor, c);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int m;
    char instr;
    cin >> s;
    for (char c : s)
        str.push_back(c);
    cursor = str.end();
    cin >> m;
    while (m > 0) {
        cin >> instr;
        switch (instr) {
        case 'L':
            instr_L();
            break;
        case 'D':
            instr_D();
            break;
        case 'B':
            instr_B();
            break;
        case 'P':
            char c;
            cin >> c;
            instr_P(c);
            break;
        }
        m--;
    }
    for (auto i : str)
        cout << i;
    return 0;
}