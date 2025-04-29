#include <iostream>
using namespace std;

enum unitMoney {
    quarter = 25,
    dime = 10,
    nickel = 5
};

int main() {
    int T, C;
    cin>>T;
    
    for(int i=0; i<T; i++){
        cin >> C;
        cout<<C/quarter<<' ';
        C %= quarter;
        cout<<C/dime<<' ';
        C %= dime;
        cout<<C/nickel<<' ';
        C %= nickel;
        cout<<C<<endl;
    }
    return 0;
}