#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int m, n;
    cin>>m>>n;
    
    int min=0, sum=0;
    double routeX = sqrt(m);
    int startNum= static_cast<int>(routeX);
    if(routeX - startNum != 0)
      startNum++;
    
    for(int r = startNum*startNum; r<=n; startNum++, r=startNum*startNum)
    {
        if(sum==0)
            min = r;
        sum+=r;
    }
    if(sum==0)
        cout<<-1<<endl;
    else
    {
        cout<<sum<<endl;
        cout<<min<<endl;
    }
    return 0;
}