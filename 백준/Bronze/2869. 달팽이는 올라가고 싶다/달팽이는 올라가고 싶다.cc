#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int A, B, V, goal;
    cin >> A >> B >> V;
    
    goal = V-A;
    if((V-A)%(A-B)==0)
        cout<<(V-A)/(A-B)+1;
    else
        cout<<(V-A)/(A-B)+2;
    
    return 0;
}