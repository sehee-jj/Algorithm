#include <iostream>>
using namespace std;

int main() {
    int N, range, i=1;
    cin >> N;
    
    range = 2;
    
    while(1)
    {
        if(N<range) {
            cout<<i;
            break;
        } else
            range += 6*i++;
    }
    return 0;
}