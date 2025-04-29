#include <iostream>
using namespace std;

class Queue {
private:
    int Q[10000];
    int* head, * tail;
    int cnt = 0;
public:
    Queue() {
        head = Q;
        tail = Q;
    }

    void push(int x) {
        *(tail++) = x;
        cnt++;
        return;
    }

    void pop() {
        if (empty()) {
            cout << -1 << "\n";
            return;
        }
        cout << *head << "\n";
        head++;
        cnt--;
        return;
    }

    const int size() {
        return cnt;
    }

    const int empty() {
        if (cnt == 0)
            return 1;
        else 
            return 0;
    }

    const int front() {
        if (empty()) {
            cout << -1 << "\n";
            return -1;
        }
        cout << *head << "\n";
        return *head;
    }

    const int back() {
        if (empty()) {
            cout << -1 << "\n";
            return -1;
        }
        cout << *(tail - 1) << "\n";
        return *(tail - 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Queue Q;
    int n;
    string op;

    cin >> n;

    while (n--) {
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            Q.push(x);
        }
        else if (op == "pop")
            Q.pop();
        else if (op == "size") {
            cout << Q.size() << "\n";
        }
        else if (op == "empty")
            cout << Q.empty() << "\n";
        else if (op == "front")
            Q.front();
        else if (op == "back")
            Q.back();
    }

    return 0;
}