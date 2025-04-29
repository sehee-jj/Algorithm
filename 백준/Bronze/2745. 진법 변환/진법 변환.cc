#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string n;
    int b, len, decimalN = 0;
    cin >> n >> b;
    len = n.length();

    for (int i = 0; i < len; i++)
    {
        if (isdigit(n[i]))
            decimalN += static_cast<int>(pow(b, len - 1 - i)) * (n[i]-48);
        else
        {
            int alphNum = n[i] - 55;
            decimalN += static_cast<int>(pow(b, len - 1 - i)) * alphNum;
        }
    }
    cout << decimalN;
    return 0;
}