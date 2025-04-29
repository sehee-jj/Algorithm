#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tri[3];
    while(cin >> tri[0] >> tri[1] >> tri[2]) {
        if(tri[0] == 0 && tri[1] == 0 && tri[2] == 0)
            break;
        sort(tri, tri+3);
        if(tri[0]+tri[1]<=tri[2])
            cout<<"Invalid"<<endl;
        else if(tri[0]==tri[1]&&tri[1]==tri[2])
            cout<<"Equilateral"<<endl;
        else if(tri[0]==tri[1]||tri[0]==tri[2]||tri[1]==tri[2])
            cout<<"Isosceles"<<endl;
        else 
            cout<<"Scalene"<<endl;
    } 
    return 0;
}