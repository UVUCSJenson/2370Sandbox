#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Date {
    int month;
    int day;
    int year;
public:
    Date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }
    friend ostream& operator<<(ostream& os, const Date& d) {
        return os << '{' << d.month << '-' << d.day << '-' << d.year << '}';
    }
    friend istream& operator>>(istream& is, Date& d) {  // month-day-year, 11-12-2020
        is >> d.month;
        if (is) {
            char c = ' ';
            is >> c;
            if(c != '-') {
                is.unget();
                is.setstate(ios::failbit);
            }
            is >> d.day;
            if (is) {
                c = ' ';
                is >> c;
                if(c != '-') {
                    is.unget();
                    is.setstate(ios::failbit);
                }
                is >> d.year;
            }
        }
        return is;
    }
};

void str_state(istream& is) {
    if (is.good())
        cout << " good";
    if (is.eof())
        cout << " eof";
    if (is.fail())
        cout << " fail";
    cout << endl;
}

int main() {
    Date d(7,17,2014);
    cout << d << endl;

    string s{"7-18-2014"};
    istringstream is(s);
    str_state(is);
    is >> d;
    cout << d << endl;
    str_state(is);

    is.str("a-19-2014");    // Reset the string stream
    is.seekg(0);            // Moves to beginning of string
    is >> d;
    cout << d << endl;
    str_state(is);
}

/* Output:
{7-17-2014}
 good
{7-18-2014}
 eof
{0-18-2014}
 fail
*/
