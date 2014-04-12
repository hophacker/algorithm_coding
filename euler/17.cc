/*
 * =====================================================================================
 *
 *       Filename:  17.cc
 *
 *    Description:  Number letter counts
 *
 *        Version:  1.0
 *        Created:  12/28/2013 12:16:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include "numberSpell.h"

int countLetters(string& s){
    int c = 0;
    for (ui i = 0; i < s.length(); i++)
        if ('a' <= s[i] && s[i] <= 'z') c ++;
    return c;
}


int main(){
    int total = 0;
    for (ui i = 1; i <= 1000; i++){
        string s = numberSpell::spell(i);
        total +=  countLetters(s);
        printf("%4i: %s\n", i, s.c_str());
    }
    cout << total << endl;
}
