#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int* seq = new int[N];

    for (int i = 0; i < N; i++)
        seq[i] = i+1;

    do {
        reverse(seq + M, seq + N);
        for(int i=0 ; i<M; i++)
            cout<<seq[i]<<' ';
        cout<<'\n';
    } while (next_permutation(seq, seq + N));

    return 0;
}