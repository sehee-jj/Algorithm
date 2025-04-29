#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    while (getline(cin, str, '.')) {
        if (str == "")
            break;
        stack<char> st;
        int i;
        for (i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[')
                st.push(str[i]);
            else if (str[i] == ')' || str[i] == ']') {
                if (st.empty() || abs(st.top() - str[i]) > 2) {
                    cout << "no\n";
                    break;
                }
                st.pop();
            }
        }
        if (i == str.length()) {
            if (st.empty())
                cout << "yes\n";
            else
                cout << "no\n";
        }
        cin.ignore();
    }
    return 0;
}