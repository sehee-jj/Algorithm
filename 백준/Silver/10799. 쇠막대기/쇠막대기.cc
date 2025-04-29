#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string bracket;
    cin>>bracket;
    
    stack<char> st;
    int cnt=0;
    
    for(int i=0; i<bracket.length(); i++) {
        if(bracket[i]==')') {
            if(bracket[i-1]=='(') {
                st.pop();
                cnt += static_cast<int>(st.size());
            }
            else {
                st.pop();
                cnt++;
            }
        }
        else
            st.push('(');
    }
    
    cout<<cnt;
    return 0;
}