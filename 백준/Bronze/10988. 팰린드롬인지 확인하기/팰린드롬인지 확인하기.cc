#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[101];
    cin>>str;
    
    int sLen = strlen(str);
    
    for(int i =0; i<sLen/2; i++)
    {
        if(str[i]!=str[sLen-1-i])
        {
            cout<<false<<endl;
            return 0;
        }
    }
    cout<<true<<endl;
    return 0;
}