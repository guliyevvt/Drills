#include <iostream>
#include <chrono>
using namespace std;

bool isLeap(int year)
{
    return (((year % 4 == 0) &&
        (year % 100 != 0)) ||
        (year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{
    if (y > 9999 ||
        y < 1500)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}

int offsetDays(int d, int m, int y)
{
    int offset = d;

    switch (m - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }

    if (isLeap(y) && m > 2)
        offset += 1;

    return offset;
}

void revoffsetDays(int offset, int y, int* d, int* m)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

void addDays(int d1, int m1, int y1, int x)
{
    int offset1 = offsetDays(d1, m1, y1);
    int remDays = isLeap(y1) ? (366 - offset1) : (365 - offset1);

    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }

    else
    {

        x -= remDays;
        y2 = y1 + 1;
        int y2days = isLeap(y2) ? 366 : 365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = isLeap(y2) ? 366 : 365;
        }
        offset2 = x;
    }

    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);

}


struct DateV1 {
    int y; // year
    int m; // month in year
    int d; // day of month
};

void init_day(DateV1& dd, int y, int m, int d)
{
    dd.y = y;
    dd.m = y;
    dd.d = d;
}
struct DateV1 add_day(DateV1& dd, int n)
{
    struct DateV1 newDate;
    init_day(newDate, dd.d, dd.m, dd.y);
    addDays(newDate.d, newDate.m, newDate.y, n);
    return newDate;
}

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class DateV2 {
public:
    class Invalid { }; // to throw as exception
    DateV2(int y, Month m, int d) {
        this->y = y;
        this->m = m;
        this->d = d;
    }
    DateV2(); // default constructor
    // the default copy operations are fine
    // nonmodifying operations:
    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }
    // modifying operations:
    DateV2 add_day(int n) {
        DateV2 newDate(y, m, d);
        int mm = (int)m;
        addDays(d, mm, y, n);
        newDate.d += 1;
        newDate.m == (Month)mm;
        return newDate;
    }
    void add_month(int n);
    void add_year(int n);
private:
    int y;
    Month m;
    int d;
};


ostream& operator<<(ostream& os, const DateV2& d) {
    os << d.day() << "/" << (int)d.month() << "/" << d.year() << "\n";
    return os;
}

int main() {
    DateV1 todayV1;
    init_day(todayV1, 25, 06, 1978);
    DateV1 tomorrowV1 = add_day(todayV1, 1);

    DateV2 todayV2(1978, Month::jul, 25);
    DateV2 tomorrowV2 = todayV2.add_day(1);

    cout << todayV2 << "\n";
    cout << tomorrowV2 << "\n";


}
