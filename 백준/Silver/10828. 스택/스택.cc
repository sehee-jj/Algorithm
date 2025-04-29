#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string command;
    stack<int> st;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "push")
        {
            int num;
            cin >> num;

            st.push(num);
        }
        else if (command == "pop")
        {
            if (st.empty())
                cout << -1 << endl;
            else
            {
                cout << st.top() << endl;
                st.pop();
            }
        }
        else if (command == "size")
        {
            if (st.empty())
                cout << 0 << endl;
            else
                cout << st.size() << endl;
        }
        else if (command == "empty")
            cout << st.empty() << endl;
        else if (command == "top")
        {
            if (st.empty())
                cout << -1 << endl;
            else
                cout << st.top() << endl;
        }
    }
}