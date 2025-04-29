#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, p;
    cin>>n;
    
    for(int i=n; i>0; i--)
    {
        cin>>p;
        int maxValue;
        char topName[21];
        cin>>maxValue>>topName;
        for(int j=p-1; j>0; j--)
        {
            int tempValue;
            char tempName[21];
            cin>>tempValue>>tempName;
            if(maxValue<tempValue)
            {
                maxValue = tempValue;
                strcpy(topName, tempName);
            }
        }
        cout<<topName<<endl;
    }
    
    return 0;
}