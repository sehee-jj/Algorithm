#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, base = 2;
    cin>>N;
    
    for(int i=0; i<N; i++) {
        base += pow(2, i);
    }
    
    cout<<static_cast<int>(pow(base, 2));
    return 0;
}