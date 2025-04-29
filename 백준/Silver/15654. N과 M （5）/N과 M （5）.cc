#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int arr[8];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    do {
        reverse(arr + M, arr + N);
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    } while (next_permutation(arr, arr + N));

    return 0;
}