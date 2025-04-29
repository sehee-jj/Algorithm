#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    long long answer = N;

    for (int i = 2; i <= N; i++)
    {
        int cnt = N/i;
        answer += cnt*i;
    }

    cout << answer;

    return 0;
}