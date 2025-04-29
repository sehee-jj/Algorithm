#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int* mtx1 = new int[n * m];
    int* mtx2 = new int[n * m];
    int* ptr = mtx1;

    for (int k = 0; k < 2; k++)
    {
        if (k == 1)
            ptr = mtx2;
        for (int i = 0; i < n * m; i++)
            cin >> ptr[i];
    }
    for (int i = 0; i < n * m; i++)
    {
        if (i != 0 && i % m == 0)
            cout << endl;
        cout << mtx1[i] + mtx2[i] << ' ';
    }
}