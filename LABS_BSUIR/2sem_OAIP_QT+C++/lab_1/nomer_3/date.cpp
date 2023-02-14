#include "date.h"

Date::Date()
{

}

Date::Date(QString given)
{
    data = given;

    days = given.mid(0, 2).toInt();
    months = 10 * given[3].digitValue() + given[4].digitValue();
    years = 1000 * given[6].digitValue() + 100 * given[7].digitValue() + 10 * given[8].digitValue() + given[9].digitValue();
}

Date::Date(int d, int m, int y)
{
    days = d;
    months = m;
    years = y;

    data = QString::number(days) + '.' + QString::number(months) + '.' + QString::number(years);
}

void Date::treatmentYears()
{
    if(this->isLeap())
    {
        daysinmonths[1]++;
    }

    if(years == 1 && months == 1 && days == 0)
    {
        data = "01.01.0001 BC";

        return;
    }

    if(days > daysinmonths[months - 1])
    {
        days -= daysinmonths[months - 1];
        months++;

    }

    if(days <= 0)
    {
        days += daysinmonths[months - 1];
        months--;
    }

    if(months > 12)
    {
        months -= 12;
        years++;
    }

    if(months < 1)
    {
        months += 12;
        years--;
    }

    if(this->isLeap())
    {
         daysinmonths[1]--;
    }

    data = QString::number(days) + '.' + QString::number(months) + '.' + QString::number(years);
}

Date Date::NextDay()
{
    Date out(days + 1, months, years);

    out.treatmentYears();

    return out;
}

Date Date::PreviousDay()
{
    Date out(days - 1, months, years);

    out.treatmentYears();

    return out;
}

bool Date::isLeap()
{
    if((years % 4 == 0 && years % 100 != 0) || years % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

short Date::WeekNumber()
{
    int daynumber = 0;

    if(this->isLeap())
    {
        daysinmonths[1]++;
    }

    for(int i = 0; i < months - 1; i++)
    {
        daynumber += daysinmonths[i];
    }

    daynumber += days;

    if(this->isLeap())
    {
        daysinmonths[1]--;
    }

    return daynumber / 7 + 1;
}

int Date::DaysTillYourBirthday(Date bithdaydate)
{
    int daynumber = 0, bithdaynumber = 0, alldayinyear = 0;

    if(this->isLeap())
    {
        daysinmonths[1]++;
    }

    if(bithdaydate.isLeap())
    {
        bithdaydate.daysinmonths[0]++;
    }

    for(int i = 0; i < 12; i++)
    {
        alldayinyear += daysinmonths[i];
    }

    for(int i = 0; i < months; i++)
    {
        daynumber += daysinmonths[i];
    }

    for(int i = 0; i < bithdaydate.months; i++)
    {
        bithdaynumber += bithdaydate.daysinmonths[i];
    }

    if(this->isLeap())
    {
        daysinmonths[1]--;
    }

    if(bithdaydate.isLeap())
    {
        bithdaydate.daysinmonths[0]--;
    }

    if(bithdaynumber >= daynumber)
    {
        return bithdaynumber - daynumber;
    }
    else
    {
        return alldayinyear - daynumber + bithdaynumber;
    }
}

int Date::Duration(Date date)
{
    int dur = 0;

    if(this->years < date.years)
    {
        if(this->isLeap())
        {
            daysinmonths[1]++;
        }

        for(int i = months - 1; i < 12; i++)
        {
            dur += daysinmonths[i];
        }

        dur -= days;

        if(this->isLeap())
        {
            daysinmonths[1]--;
        }

        for(int i = years + 1; i < date.years; i++)
        {
            if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            {
                dur += 366;
            }
            else
            {
                dur += 365;
            }
        }

        if(date.isLeap())
        {
            date.daysinmonths[1]++;
        }

        for(int i = 0; i < date.months - 1; i++)
        {
            dur += date.daysinmonths[i];
        }

        dur += date.days;

        if(date.isLeap())
        {
            date.daysinmonths[1]--;
        }
    }
    else if(this->years == date.years)
    {
        int daynumber = 0, datedaynumber = 0;

        if(this->isLeap())
        {
            daysinmonths[1]++;
            date.daysinmonths[1]++;
        }

        for(int i = 0; i < months - 1; i++)
        {
            daynumber += daysinmonths[i];
        }

        daynumber += days;

        for(int i = 0; i < date.months - 1; i++)
        {
            datedaynumber += date.daysinmonths[i];
        }

        datedaynumber += date.days;

        if(this->isLeap())
        {
            daysinmonths[1]++;
            date.daysinmonths[1]++;
        }

        dur = abs(datedaynumber - daynumber);
    }
    else
    {
        if(date.isLeap())
        {
            date.daysinmonths[1]++;
        }

        for(int i = date.months - 1; i < 12; i++)
        {
            dur += date.daysinmonths[i];
        }

        dur -= date.days;

        if(this->isLeap())
        {
            date.daysinmonths[1]--;
        }

        for(int i = date.years + 1; i <= years; i++)
        {
            if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            {
                dur += 366;
            }
            else
            {
                dur += 365;
            }
        }

        if(this->isLeap())
        {
            daysinmonths[1]++;
        }

        for(int i = 0; i < months - 1; i++)
        {
            dur += daysinmonths[i];
        }

        dur += days;

        if(this->isLeap())
        {
            daysinmonths[1]--;
        }
    }

    return dur;
}


