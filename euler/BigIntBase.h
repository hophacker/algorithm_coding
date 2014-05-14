#define DEBUG 

#ifndef BIGINTBASE_H
#define BIGINTBASE_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;
#define bit(x,i) (x&(1<<i))
#define ui unsigned int
typedef unsigned char BigUnit;

/*
 * 1.Due to the following reasons, I created BigIntBase as the array type for BigInteger:
 *   A.vector has so many problems when used as class member, ex,
 *     when you use push_back(), When you call std::vector::push_back(), a copy 
 *     of the argument is made before adding it to the vector. 
 *   B.The expansion speed for BigInteger's array is very different from the default
 *     expansion speed of STL::vector, I need to control the expansion.
 *   C.The type for BigUnit is still changing, if I use bit instead of "usnsigned char",
 *     the implementation mechanism may very different, which is difficult to employ
 *     the funcionality of STL::vector.
 * 2.Representation of ingeter:
 *   A. If size==0, the value is undefined.
 *   B. If size==1 && data[i] == 0, the value is 0.
 */

class BigIntBase{
private:
    //Reverve "addCapacity" BigUnit to prevent early expanding. For example, divide method needs to put
    //one 0 before the highest digit of dividend.
    //In operator*=(int), we need to reserve 10(max length of int) more BigUnit space for this calculation
    //since it is caculated in *this
    const static ui addCapacity = 10;
    //max capacity for int 32 is 10
    const static ui capacityOfI32 = 10 + addCapacity;
    /* This constructor is convenient when an object with specific capacity is needed inside the class
     */
    BigIntBase(bool forCapacity, ui _capacity);
    BigIntBase(ui val, ui _capacity);
    BigIntBase(int val, ui _capacity);
    unsigned GetNumberOfDigits (unsigned i) {
        return i > 0 ? (int) log10 ((double) i) + 1 : 1;
    }
    void setCapacity(ui length);
    //This is a member function Initializing unsigned int which is shared by "BigIntBase(ui)" and "BigIntBase(int)"
    //I was so sad that C++ does not support calling constructor inside of another constructor, which is convenient,
    //if wrote "BigIntBase(int n)" as "assert(n >= 0); BigIntBase((ui)(n));".
    //However, there is another choice, which is to delegate constructor by using  "BigIntBase(int n):BigIntBase((ui)(n)){}".
    //But, every time the compiler compiles with annoying warning message:"delegating constructors only available with -std=c++11 or -std=gnu++11".
    void initializeUI(ui n);
public:
    ui size;
    ui capacity;
    BigUnit* data = NULL;
    static const BigUnit digitMul[][10];
public:
    BigIntBase();
    BigIntBase(ui n){initializeUI(n);}
    BigIntBase(int n){assert(n >= 0); initializeUI((ui)n);}
    /* 
     * The input char array can only contain "0-9", for example, 
     * (1) "987643"
     * (3) "00987643"
     * otherwise the result is not defined.
     */
    BigIntBase(const char* numStr);
    BigIntBase(const BigIntBase& rhs);

    /* This constructor method is used when you need a object to be copied with the capacity you want.
     * for example, when multiplication occurs.
     */
    BigIntBase(const BigIntBase& rhs, int rhsCapacity);
    static BigIntBase ONE(){
        BigIntBase res;
        res.setCapacity(1);
        res.size = 1;
        res[0] = 1;
        return res;
    }
    inline bool setZero(){
        if (capacity == 0) setCapacity(1);
        size = 1; 
        data[0] = 0;
    }
    inline bool isZero(){
        return (size == 1 && data[0] == 0 || size == 0);
    }
    inline bool isOne(){
        return (size == 1 && data[0] == 1);
    }
    int subCompare(int t, ui len, BigIntBase &b);
    int compare(BigIntBase &b);
    BigUnit calcDigit(int pos, ui len, BigIntBase* B);
    void assign(const BigIntBase& rhs);
    void assign(ui val);
    void assign(int val);
    void clear(ui length, BigUnit value);
    void expand(int newCapacity);
    BigUnit& operator[](const ui idx);
    void add(BigIntBase &a, BigIntBase &b);
    void subtract(BigIntBase &a, BigIntBase &b);
    void subtract(int pos, BigIntBase &b);
    void multiply(BigIntBase &a, BigIntBase &b);
    void multiply(BigIntBase &a, int b);
    BigIntBase divide(BigIntBase &a, BigIntBase &b);
    void shrink(){
        while( size > 0 && data[size-1] == 0) size--;
    }
    BigIntBase square();
    BigIntBase& operator=(const BigIntBase &rhs);
    BigIntBase& operator=(const int rhs);
    BigIntBase operator+(BigIntBase& b);
    BigIntBase operator+=(BigIntBase& b);
    BigIntBase operator-(BigIntBase& b);
    void operator-=(BigIntBase& b);
    void operator-=(int b);
    void operator-=(ui b);
    BigIntBase& operator--();
    BigIntBase operator*(BigIntBase &b);
    BigIntBase operator*(int b);
    void operator*=(BigIntBase& b);
    void operator*=(ui b);
    BigIntBase operator/(BigIntBase &b);
    void operator/=(BigIntBase& b);
    BigIntBase operator%(BigIntBase &b);
    void operator%=(BigIntBase& b);
    string toStringInBase(ui base);
    friend ostream& operator <<(ostream &os, BigIntBase& n);
    void print();
    //Algorithms
    BigIntBase gcd(BigIntBase &b);
    BigIntBase pow(ui n);
    static BigIntBase factorial(int n);
    static BigIntBase permutation(int a, int b);
    static BigIntBase combination(int a, int b);

    bool isPalindrome();
    //bool isPrime();
/*     static bool isEven(const BigInt&);
 *     static BigInt reverseNumber(const BigInt&);
 *     static long sumOfDigit(const BigInt&);
 *     static int numberOfDigit(const BigInt&);
 * 
 */
};
#endif
