#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include "../euler.h"
#include "BigVector.cc"
#define BigUnit unsigned char
using namespace std;

class BigInteger{
public:
    bool pos;
    BigVector data;
private:
public:
    BigInteger(): pos(true), data(BigVector()){}
	BigInteger(int n): pos(n>=0), data( BigVector( (ui)(abs(n)) ) ){}
	BigInteger(ui n): pos(true), data( BigVector(n) ){}
	BigInteger(bool pos, BigVector &dataNow): pos(true), data(dataNow) ){}
    /* 
     * The input char array can only contain "+-0-9", for example, 
     * (1) "987643"
     * (2) "+987643"
     * (3) "-987643"
     * otherwise the result is not defined.
     */
    BigInteger(char* numStr){
        if (numStr[0] == '-') {
            pos = false;
            data = BigVector(numStr+1);
        }else{
            pos = true;
            data = BigVector( numStr + (numStr[0]=='+'?1:0) );
        }
    }
    BigInteger BigInteger::operator+(const BigInteger&b);
    inline ui size(){ return data.size; }
    string toStringInBase(ui base);
};
ostream& operator <<(ostream&, const BigInteger&);
#endif
