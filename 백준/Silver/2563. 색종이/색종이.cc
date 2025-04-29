#include <iostream>
using namespace std;

int main()
{
    bool whiteboard[100][100] = {false};

    int n, area = 0;
    cin >> n;

    for (n; n > 0; n--)
    {
        int x, y;
        cin >> x >> y;

        for (int i = x; i < 10 + x; i++)
        {
            for (int j = y; j < 10 + y; j++)
            {
                if (!whiteboard[i][j])
                {
                    area++;
                    whiteboard[i][j] = true;
                }
            }
        }
    }
    cout << area;
    return 0;
}