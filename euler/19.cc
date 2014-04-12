/*
 * =====================================================================================
 *
 *       Filename:  19.cc
 *
 *    Description:  Counting Sundays
 *
 *        Version:  1.0
 *        Created:  12/28/2013 01:46:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include "euler.h"

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
    cout << isLeapYear(1992) << endl;
    cout << isLeapYear(1990) << endl;
    cout << isLeapYear(2000) << endl;
    int weekday = 1;
    int month,year;
    int total = 0;
    for (year = 1900; year <= 2000; year++){
        if (isLeapYear(year)) days[2] = 29;
        else days[2] = 28;
        for (month=(year==1900?2:1); month <= 12; month++){
            if (month == 1)
                weekday = (weekday + days[12]) % 7;
            else weekday = (weekday + days[month-1]) % 7;
            if (!weekday) {
                if (year >= 1901) total ++;
                cout << year << ' ' << month << endl;
            }
        }
    }
    cout << total << endl;
}
