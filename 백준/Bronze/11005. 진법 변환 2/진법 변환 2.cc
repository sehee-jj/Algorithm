#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, b, divNum;
    cin >> n >> b;
    divNum = n;
    vector<char> conv;

    while (divNum != 0)
    {
        int convNum = divNum % b;
        if (convNum >= 10)
            conv.insert(conv.begin(), convNum+55);
        else
            conv.insert(conv.begin(), convNum+'0');
        divNum /= b;
    }

    for (auto v : conv)
        cout << v;
    return 0;
}