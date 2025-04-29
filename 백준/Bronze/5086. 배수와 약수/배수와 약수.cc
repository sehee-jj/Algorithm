#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cin>>n1>>n2;
    while(n1!=0&&n2!=0) {
        if(n2%n1==0)
            cout<<"factor"<<endl;
        else if(n1%n2==0)
            cout<<"multiple"<<endl;
        else
            cout<<"neither"<<endl;
        cin>>n1>>n2;
    }
    return 0;
}