/*
 * =====================================================================================
 *
 *       Filename:  BigInteger.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/25/2013 04:45:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jie Feng (http://hey.i-feng.org/), jokerfeng2010@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "BigInteger.h"
string BigInteger::toStringInBase(ui base){
    ui size = this->data.size;
    string s(size, ' ');
    for (ui i = 0; i < size; i++)
        s[i] = this->data[size-1-i]+'0';
    return s;
}
BigInteger BigInteger::operator+(const BigInteger& b){
    a = this;
    c = new BigInteger();
}
std::ostream& operator <<(ostream &os, BigInteger& n) {
/* 
	BigUnsignedInABase::Base base;
	long osFlags = os.flags();
	if (osFlags & os.dec)
		base = 10;
	else if (osFlags & os.hex) {
		base = 16;
		if (osFlags & os.showbase)
			os << "0x";
	} else if (osFlags & os.oct) {
		base = 8;
		if (osFlags & os.showbase)
			os << '0';
	} else
		throw "std::ostream << BigUnsigned: Could not determine the desired base from output-stream flags";
*/
    if (!n.pos) os << "-";
    os << n.toStringInBase(10);
    return os;
}
int main(){
    BigInteger b("-123");
    cout << b << endl;
}
