#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int st, int dst) {
    if (n == 1) {
        cout << st << ' ' << dst << "\n";
        return;
    }
    hanoi(n - 1, st, 6 - st - dst);
    cout << st << ' ' << dst << "\n";
    hanoi(n - 1, 6 - st - dst, dst);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (int)pow(2, n) - 1 << "\n";
    hanoi(n, 1, 3);

    return 0;
}