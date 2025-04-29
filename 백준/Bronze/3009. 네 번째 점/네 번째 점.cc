#include <iostream>
using namespace std;

int main() {
    int x[3], y[3];
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    cout << static_cast<int>(x[0] ^ x[1] ^ x[2]) << ' ' << static_cast<int>(y[0] ^ y[1] ^ y[2]);
    return 0;
}