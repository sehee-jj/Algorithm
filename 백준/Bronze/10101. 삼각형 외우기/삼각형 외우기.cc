#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    
    if(x+y+z != 180)
        cout<<"Error";
    else if(x==y&&y==z)
        cout<<"Equilateral";
    else if(x==y||x==z||y==z)
        cout<<"Isosceles";
    else
        cout<<"Scalene";
    return 0;
}