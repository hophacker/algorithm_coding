/*
 * =====================================================================================
 *
 *       Filename:  numberSpelling.cc
 *
 *    Description:  spelling number
 *
 *        Version:  1.0
 *        Created:  12/27/2013 10:56:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "numberSpell.h"

const char* numberSpell::baseNumberString[] = {
    "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
};
const char* numberSpell::tensString[] = {
    NULL, NULL, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", 
    "eighty", "ninety"
};
string numberSpell::spell(ui n){
    assert(0 <= n && n < 10000);
    return numberSpell::spellThousands(n);
}
string numberSpell::spellBase(ui n){
    return numberSpell::baseNumberString[n];
}
string numberSpell::spellTens(ui n){
    string res;
    if (n >= 20){
        res += tensString[n/10];
        n %= 10;
        if (n) res += "-";
    }
    if (n) res += baseNumberString[n];
    return res;
}
string numberSpell::spellHundreds(ui n){
    string res;
    if (n > 99){
        res = baseNumberString[n/100];
        res += " hundred";
        n %= 100;
        if (n) res += " and ";
    }
    if (n) {
        res += spellTens(n);
    }
    return res;
}
string numberSpell::spellThousands(ui n){
    string res;
    if (n > 999){
        res = baseNumberString[n/1000];
        res += " thousand ";
        n %= 1000;
    }
    if (n) {
        res += spellHundreds(n);
    }
    return res;
}
