#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> exStr = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string str;
    cin >> str;
    
    for(auto ex : exStr)
    {
        int hitIdx = str.find(ex);
        while(hitIdx != string::npos)
        {
            str.replace(hitIdx, ex.length(), "#");
            hitIdx = str.find(ex);
        }
    }
    cout<<str.length()<<endl;
    return 0;
}