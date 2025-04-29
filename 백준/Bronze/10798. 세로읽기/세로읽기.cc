#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string result[15];
    fill_n(result, 15, "");
    string str;
    int maxLen = 0;

    while (cin >> str)
    {
        for (int i = 0; i < str.length(); i++)
            result[i] += str[i];
        maxLen = max(static_cast<int>(str.length()), maxLen);
    }
    for (int i = 0; i < maxLen; i++)
        cout << result[i];
    return 0;
}