#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, double> grade;
    grade.insert({ "A+", 4.5 });
    grade.insert({ "A0", 4.0 });
    grade.insert({ "B+", 3.5 });
    grade.insert({ "B0", 3.0 });
    grade.insert({ "C+", 2.5 });
    grade.insert({ "C0", 2.0 });
    grade.insert({ "D+", 1.5 });
    grade.insert({ "D0", 1.0 });
    grade.insert({ "F", 0.0 });

    double sumCrd, sumGrd;
    for (int i = 0; i < 20; i++)
    {
        string subject, grd;
        double crd;

        cin >> subject; //?
        cin >> crd >> grd;

        if (grd == "P")
            continue;

        sumCrd += crd;
        sumGrd += crd * grade[grd];
    }
    cout << sumGrd / sumCrd << endl;
    return 0;
}