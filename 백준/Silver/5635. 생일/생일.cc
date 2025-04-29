#include <iostream>
#include <string>
using namespace std;

class student
{
private:
    string name;
    int bDay, bMonth, bYear;
public:
    student() : bDay(0), bMonth(0), bYear(0) {}
    student(string n, int d, int m, int y) : name(n), bDay(d), bMonth(m), bYear(y) {}
    string getName()
    {
        return name;
    }
    int getBirthDay()
    {
        return bDay;
    }
    int getBirthMonth()
    {
        return bMonth;
    }
    int getBirthYear()
    {
        return bYear;
    }
};

int main()
{
    int stNum;
    cin >> stNum;
    cin.ignore();
    student stList[100];

    for (int i = 0; i < stNum; i++) {
        string name;
        int day, month, year;
        getline(cin, name, ' ');
        cin >> day >> month >> year;
        cin.ignore();
        stList[i] = student(name, day, month, year);
    }

    student oldMan = stList[0];
    student youngMan = stList[0];

    for (int i = 1; i < stNum; i++)
    {
        if (stList[i].getBirthYear() < oldMan.getBirthYear())
            oldMan = stList[i];
        else if (stList[i].getBirthYear() == oldMan.getBirthYear())
        {
            if (stList[i].getBirthMonth() < oldMan.getBirthMonth())
                oldMan = stList[i];
            else if (stList[i].getBirthMonth() == oldMan.getBirthMonth())
                if (stList[i].getBirthDay() < oldMan.getBirthDay())
                    oldMan = stList[i];
        }

        if (stList[i].getBirthYear() > youngMan.getBirthYear())
            youngMan = stList[i];
        else if (stList[i].getBirthYear() == youngMan.getBirthYear())
        {
            if (stList[i].getBirthMonth() > youngMan.getBirthMonth())
                youngMan = stList[i];
            else if (stList[i].getBirthMonth() == youngMan.getBirthMonth())
                if (stList[i].getBirthDay() > youngMan.getBirthDay())
                    youngMan = stList[i];
        }
    }

    cout << youngMan.getName() << endl;
    cout << oldMan.getName();

    return 0;
}