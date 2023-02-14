#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QDateTime>

class Date
{
public:
    Date();
    Date(QString given);
    Date(int d, int m, int y);

    int days, months, years;
    int daysinmonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    QString data;

    void treatmentYears();

    Date NextDay();
    Date PreviousDay();
    bool isLeap();
    short WeekNumber();
    int DaysTillYourBirthday(Date bithdaydate);
    int Duration(Date date);
};

#endif // DATE_H
