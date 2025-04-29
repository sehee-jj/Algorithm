#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num, max=-1;
    pair<int, int> idx;
    
    for(int i=1; i<10; i++)
    {
        for(int j=1; j<10; j++)
        {
            cin>>num;
            if(max<num)
            {
                max = num;
                idx = make_pair(i, j);
            }
        }
    }
    cout<<max<<endl;
    cout<<idx.first<<' '<<idx.second;
}