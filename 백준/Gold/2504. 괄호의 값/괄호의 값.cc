#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct oper {
    int p;
    char op;
};

stack<oper> operation;
stack<int> num;

void calc() {
    int x, y;
    char op;
    x = num.top();
    num.pop();
    y = num.top();
    num.pop();
    op = operation.top().op;
    operation.pop();

    if (op == '*')
        num.push(x * y);
    else if (op == '/')
        num.push(x / y);
    else if (op == '+')
        num.push(x + y);
    else if (op == '-')
        num.push(x - y);

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input, result = "";
    cin >> input;

    stack<char> bracket;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ')' || input[i] == ']') {
            if (bracket.empty() || abs(input[i] - bracket.top()) > 2) {
                cout << 0;
                return 0;
            }
            else if (bracket.top() == '(') {
                if (input[i - 1] == '(')
                    result.append("2");
                else
                    result.append(")*2");
            }
            else {
                if (input[i - 1] == '[')
                    result.append("3");
                else
                    result.append(")*3");
            }
            bracket.pop();
        }
        else {
            if (i != 0) {
                if (input[i - 1] == '(' || input[i - 1] == '[')
                    result.append("(");
                else if (input[i - 1] == ')' || input[i - 1] == ']')
                    result.append("+");
            }
            bracket.push(input[i]);
        }
    }

    if (!bracket.empty()) {
        cout << 0;
        return 0;
    }

    for (char c : result) {
        if (c == '(')
            operation.push({ 0 ,'(' });
        else if (c == ')') {
            while (operation.top().op != '(')
                calc();
            operation.pop();
        }
        else if (c == '*' || c == '/' || c == '+' || c == '-') {
            int prior;
            if (c == '*' || c == '/')
                prior = 2;
            else if (c == '+' || c == '-')
                prior = 1;

            while (!operation.empty() && prior <= operation.top().p)
                calc();
            operation.push({ prior, c });
        }
        else
            num.push(c - '0');
    }

    while (!operation.empty())
        calc();
    cout << num.top();

    return 0;
}